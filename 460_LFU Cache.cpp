class LFUCache {
private:
	struct InnerNode {
		int key;
		int value;
		
		InnerNode* pre;
		InnerNode* next;
		
		InnerNode(int ikey, int ival): key(ikey),
			value(ival), pre(NULL), next(NULL) {}
	};

	struct FqNode {
		int freqency;
		InnerNode* ihead;
		InnerNode* itail;
		
		FqNode *next;
		FqNode *pre;
		
		FqNode(int fq): freqency(fq), ihead(NULL), itail(NULL), 
			next(NULL), pre(NULL) {}
	};

	int lfuCap = 0;
	FqNode* head;
	FqNode* tail;
	unordered_map<int, pair<FqNode*, InnerNode*>> hashmap;
   
	void update_fq(int& key) {
		FqNode* fnode = hashmap[key].first;
		InnerNode* inode = hashmap[key].second;

		/* remove inode from fnode*/
		removeInode(inode, fnode);

		/* insert inode into fnode->next */
		if (!fnode->next || (fnode->next->freqency != fnode->freqency+1)) {
			FqNode* nnode = new FqNode(fnode->freqency+1);
			if (fnode->next && fnode->next->freqency != (fnode->freqency+1)) {
				nnode->next = fnode->next;
				fnode->next->pre = nnode;
			}
			else {
				tail = nnode;
			}

			fnode->next = nnode;
			nnode->pre  = fnode;
		}

		FqNode* nfnode = fnode->next;
        /* hash map should change the fnode pointer */
        hashmap[key].first = nfnode;
		
		if (!nfnode->ihead) {
			nfnode->itail = inode;
			nfnode->ihead = inode;
		}
		else {
			nfnode->ihead->pre = inode;
			inode->next  = nfnode->ihead;
			nfnode->ihead = inode;
		}

		if (!fnode->ihead) {
			/* delete the fnode */
			removeFnode(fnode);
		}
	}

	void removeFnode(FqNode* fnode) {
        if (fnode == head && fnode == tail) {
            head = NULL;
            tail = NULL;
        }
        else if (fnode == head) {
			head = fnode->next;
			if (fnode->next)
				fnode->next->pre = NULL;
		}
		else if (fnode == tail) {
			fnode->pre->next = NULL;
		}
		else {
			fnode->pre->next = fnode->next;
			fnode->next->pre = fnode->pre;
		}
		fnode->next = NULL;
		fnode->pre  = NULL;
		delete fnode;
	}

	void removeInode(InnerNode* inode, FqNode* fnode) {
		if (inode == fnode->ihead && inode == fnode->itail) {
			fnode->ihead = NULL;
			fnode->itail  = NULL;
		}
		else if (inode == fnode->ihead) {
			fnode->ihead = inode->next;
			fnode->ihead->pre = NULL;
		}
		else if (inode == fnode->itail) {
			fnode->itail = inode->pre;
			fnode->itail->next = NULL;
		}
		else {
			inode->next->pre = inode->pre;
			inode->pre->next = inode->next;
		}

		inode->pre = NULL;
		inode->next = NULL;
	}

public:
	LFUCache(int capacity) {
        head = NULL;
        tail = NULL;
		lfuCap = capacity;
	}

	int get(int key) {
		if (hashmap.count(key)) {
			int res = hashmap[key].second->value;
			update_fq(key);
			return res;
		}
		return -1;
	}

	void put(int key, int value) {
		if (lfuCap < 1)
			return;
		if (hashmap.count(key)) {
			hashmap[key].second->value = value;
			update_fq(key);
			return;
		}
        
		if (hashmap.size() >= lfuCap) {
            hashmap.erase(head->itail->key);
			removeInode(head->itail, head);
		}
		InnerNode* node = new InnerNode(key, value);
		if (!head) {
			FqNode* fnode = new FqNode(1);
			head = fnode;
			head->ihead = node;
			head->itail = node;
			tail = fnode;
		}
		else if (head->freqency != 1) {
			if (!head->ihead)
				removeFnode(head);
			FqNode* fnode = new FqNode(1);
            if (!head) {
                fnode->ihead = node;
                fnode->itail = node;
                head = fnode;
                tail = fnode;
            }
            else  {
                fnode->next = head;
                head->pre   = fnode;
                head        = fnode;
                head->ihead = node;
                head->itail = node; 
            }
		}
		else {
			if (!head->ihead) {
				head->ihead = node;
				head->itail = node;
			}
			else {
				node->next = head->ihead;
				head->ihead->pre = node;
				head->ihead = node;
			}
		}
		hashmap[key] = {head, node};
	}
};

/* the idea: double linked list & hash-map. This time we use two double liked list. 
 * The idea is to build frequncy node, where each frequncy linked list node contain 
 * a linked list storing the real key-value. So that our structure is to use a external
 * double linked list node contained a double linked list. The external linked list is
 * sorted in ascending frequency order, while the inner double list node is the same as 
 * LRU desgin which is sorted by timestamp. Meanwhile we also need a hash-map to mapping
 * key to its correcponding freqcency-node and inner-node pointers;
 * The process: get() is easy, once we find hash-map has such key, we return it, remember also
 * to update the frequncy list, that is move the inner node from current frequency node to next
 * frequency node, NOTICE the next frequncy node might not suitable! 
 * The process: put() is two ways: if we find hash-map already has the key, just update it and do
 * the same frequency update. Otherwise, we need to first check if capacity reached the limit, if so
 * we should remove the least-frequncy which is least-recent used one, that is the inner tail node of 
 * the head of frequency list; then we add the new node into list and hash-map */
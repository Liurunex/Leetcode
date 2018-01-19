class LRUCache {
private:
	struct Dlist {
		int key;
		int value;
		Dlist* pre;
		Dlist* next;
		Dlist(int ikey, int ivalue): 
			key(ikey), value(ivalue), pre(NULL), next(NULL) {}
	};

	Dlist *head = NULL;
	Dlist *tail = NULL;
	unordered_map<int, Dlist*> hashmap;
	int cap = 0;

	void moveToTop(Dlist* node) {
		if (node == head) return;
		if (node == tail) {
			tail = node->pre;
			tail->next = NULL;
			node->pre  = NULL;
			
			node->next = head;
			head->pre  = node;
			head = node;
			return;
		}
		node->pre->next = node->next;
		node->next->pre = node->pre;

		node->pre  = NULL;
		node->next = head;
		head->pre  = node;
		head = node;
	}

public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (!hashmap.count(key))
			return -1;
		Dlist* node = hashmap[key];
		moveToTop(node);
		return node->value;
	}

	void put(int key, int value) {
		if (hashmap.count(key)) {
			Dlist* node = hashmap[key];
			node->value = value;
			moveToTop(node);

			return;
		}

		Dlist* node = new Dlist(key, value);
		hashmap[key] = node;
		if (head) {
			node->next 	= head;
			head->pre  	= node;
			head 		= node;
		}
		else {
			head = node;
			tail = node;
		}

		if (hashmap.size() > cap) {
			hashmap.erase(tail->key);
			
			Dlist* tem = tail;
			if (tail == head) {
				head = NULL;
				tail = NULL;
			}
			else {
				tail = tail->pre;
				tail->next = NULL;
			}

			delete tem;
			tem = NULL;
		}
	}
};

/* the idea: Double-Linked List + HashMap. Since we want both put() and get() run
 * in O(1), hashmap can help on find the one in O(1), double-linked list help on 
 * maintain the most-recent-memory-first and least-recent-memory-last policies. In
 * detail, we use hashmap to mapping each key to correcponding linked-list node. For
 * the process of get(): first check if hash-map has the key, if so we just extract
 * that list node, move it to top of our double-linked list and return the value; for
 * the put(), we first check if hash-map has the key, if so, replace the node of thek key
 * with the new coming one and move it to the top of dlist; otherwise we will
 * new a node and insert it at top of dlist, then go check the capcacity has reached the
 * limit so that we might remove the tail node to maitain the capcaity limit*/
/* NOTICE: BE REALLY CAREFUL WHEN DEALING WITH DOUBLE LINKED LIST NODE UPDATE!!
 */

/* more easy way by using built-in list */
class LRUCache {
private:
	list<pair<int, int>> dlist;
	unordered_map<int, list<pair<int, int>>::iterator> hashmap;
	int cap = 0;

public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (!hashmap.count(key))
			return -1;
		Dlist* node = hashmap[key];
		moveToTop(node);
		return node->value;
	}

	void put(int key, int value) {
		if (hashmap.count(key)) {
			Dlist* node = hashmap[key];
			node->value = value;
			moveToTop(node);

			return;
		}

		Dlist* node = new Dlist(key, value);
		hashmap[key] = node;
		if (head) {
			node->next 	= head;
			head->pre  	= node;
			head 		= node;
		}
		else {
			head = node;
			tail = node;
		}

		if (hashmap.size() > cap) {
			hashmap.erase(tail->key);
			
			Dlist* tem = tail;
			if (tail == head) {
				head = NULL;
				tail = NULL;
			}
			else {
				tail = tail->pre;
				tail->next = NULL;
			}

			delete tem;
			tem = NULL;
		}
	}
};







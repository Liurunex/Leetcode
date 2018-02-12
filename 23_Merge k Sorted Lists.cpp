class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        int right = lists.size()-1;
        while (right > 0) {
            int left = 0;
            while (left < right) {
                lists[left] = mergeTwoLists(lists[left], lists[right]);
                left ++;
                right --;
            }
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            }
            else {
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
            }
        }
        ListNode* left = l1 ? l1:l2;
        dummy->next = left;
        return res->next;
    }
};
// divide and conquer solution above
class Solution {
public:
	struct newcomparasion {
		bool operator() (const ListNode* a, const ListNode *b) { return a->val > b->val; }	
	};
	
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (!lists.size()) return NULL;
		ListNode *res = new ListNode(0);
		ListNode *dummy = res;
		priority_queue<ListNode*, vector<ListNode*>, newcomparasion> mypq;

		/* add the k nodes into pq */
		for (size_t i = 0; i < lists.size(); ++ i)
			if (lists[i] != NULL) mypq.push(lists[i]);

		while(!mypq.empty()) {
			ListNode* tem = mypq.top();
			dummy->next = tem;
			mypq.pop();
			if (tem->next != NULL) mypq.push(tem->next);
			dummy = dummy->next;
		}
		return res->next;
	}
};
/*
the thougth here is put all minium nodes of all linked list into a priority queue, each time we pop the
minium one in pq to assign it as the next ndoe of our final linked list, once we did that, we need to upadate
the pq by adding the next element of the linked list where the poped one belonging to,

the time complicity: the size of pq is always k, then each time we upadte pq is logk, we totally have to inesrt n*k times
then we got total time complicity O(n*k*logk), the space complicity is O(k)
 */


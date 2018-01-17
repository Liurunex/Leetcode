/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	ListNode* thead;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		thead = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode* tem = thead->next;
		ListNode* res = thead;
		int i = 2;
		//srand (time(NULL));
		while (tem) {
			int pos = rand() % i + 1;
			if (pos == i)
				res = tem;
			tem = tem->next;
			i ++;
		}
		return res->val;
	}
};
/* the idea: Reservoir Sampling Random Algorithm. NOTICE how to use srand() to
 * intialize the random seed, if we set the seed all the same, we will always get
 * same random number */
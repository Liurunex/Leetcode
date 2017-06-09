/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int bouns = 0;
    	ListNode *res = new ListNode(0);
    	ListNode *resCur = res;
    	while (1) {
    		if (l1 != NULL) { 
    			bouns += l1->val;
    			l1 = l1->next;
    		}
    		if (l2 != NULL) {
    			bouns += l2->val;
    			l2 = l2->next;
    		}
    		resCur->val = bouns % 10;
    		bouns = bouns > 9 ? 1:0;
    		if (l1 != NULL || l2 != NULL || bouns > 0) {
    			resCur->next = new ListNode(0);
    			resCur = resCur->next;
    		}
    		else break;
    	}

    	return res;
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
    	if (!head || !head->next) return head;
		ListNode* iter 		= head->next;
		ListNode* duplicate = head;

    	while (iter != NULL) {
    		if (iter->val == duplicate->val) {
				ListNode *tem 	= iter;
				duplicate->next = iter->next;
				iter            = iter->next;
				delete tem;
				tem = NULL;
    		}
    		else {
    			duplicate = iter;
    			iter = iter->next;
    		}
    	}   
    	return head;
    }
};
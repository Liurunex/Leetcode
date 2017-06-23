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
		ListNode* iter      = head->next;
		ListNode* duplicate = head;
		int need_to_delete  = 0;

    	while (iter != NULL) {
    		if (iter->val == duplicate->val) {
				ListNode *tem   = iter;
				duplicate->next = iter->next;
				iter            = iter->next;
				need_to_delete  = 1;
				delete tem;
				tem = NULL;
			}
			else {
				if (need_to_delete) {
					ListNode *tem   = duplicate->next;
					duplicate->next = iter->next;
					duplicate->val  = iter->val;
					iter = iter->next;
					delete tem;
					tem = NULL;
					need_to_delete  = 0;
				}
				else {
					duplicate = iter;
					iter = iter->next;
				}
			}
    	}
		if (need_to_delete) {
			ListNode *dummy = head;
			if (!head->next) { delete head; head = NULL; }
			else {
				ListNode *father = NULL;
				while (dummy->next) {
					father = dummy;
					dummy = dummy->next;
				}
				father->next = NULL;
				delete dummy;
				dummy = NULL;
			}
		}
    	return head;
    }
};

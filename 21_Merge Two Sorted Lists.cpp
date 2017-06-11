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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0);
		ListNode* res = dummy;
		while (l1 && l2) {
			if (l1->val >= l2->val) {
				dummy->next = l2;
				dummy = l2;
				l2 = l2->next;
			}
			else {
				dummy->next = l1;
				dummy = l1;
				l1 = l1->next;
			}
		}
		ListNode* left = l1 == NULL ? l2:l1;
		while (left) {
			dummy->next = left;
			dummy = left;
			left = left->next;
		}
		return res->next;
	}
};

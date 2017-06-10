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
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *reverseFormer = NULL;
		while (head->next) {
			ListNode *next = head->next;
			head->next = reverseFormer;
			reverseFormer = head;
			head = next;
		}
		head->next = reverseFormer;
		return head;
	}
};

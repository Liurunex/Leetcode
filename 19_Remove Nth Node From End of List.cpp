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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if (!head || !head->next) return NULL;
		if (n == 1) { 
			ListNode* iter = head;
			while (head->next->next) head = head->next;
			ListNode* tem = head->next;
			head->next = NULL;
			delete tem;
			tem = NULL;
			return iter;
		}

		ListNode* first_pointer = head;
		for (int i = 0; i < n-1; ++ i) 
			first_pointer = first_pointer->next;
		ListNode* second_pointer = head;
		while (first_pointer->next) {
			first_pointer  = first_pointer->next;
			second_pointer = second_pointer->next;
		}

		ListNode *tem = second_pointer->next;
		second_pointer->val  = tem->val;
		second_pointer->next = tem->next;
		delete tem;
		tem = NULL;
		
		return head;
    }
};
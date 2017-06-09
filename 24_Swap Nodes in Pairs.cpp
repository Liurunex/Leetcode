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
    ListNode* swapPairs(ListNode* head) {
    	if (head == NULL)
    		return head;
    	if (head->next == NULL)
    		return head;
    	ListNode* next = head->next->next;
    	ListNode* rehead = head->next;
    	head->next->next = head;
    	head->next = swapPairs(next);
		return rehead;
    }
};
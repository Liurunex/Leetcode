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
    bool isPalindrome(ListNode* head) {
    	if (!head || !head->next) return true;
    	ListNode* fast = head;
    	ListNode* slow = head;
    	while (fast->next && fast->next->next) {
    		fast = fast->next->next;
    		slow = slow->next;
    	}

    	ListNode* back = slow->next;
    	ListNode* bpre = NULL;
    	ListNode* bnext = NULL;
    	while (back) {
    		bnext = back->next;
    		back->next = bpre;
    		bpre = back;
    		back = bnext;
    	}

    	slow->next = bpre;
    	slow = slow->next;
    	while (slow) {
    		if (head->val != slow->val) return false;
    		head = head->next;
    		slow = slow->next;
    	}
    	return true;
    }
};
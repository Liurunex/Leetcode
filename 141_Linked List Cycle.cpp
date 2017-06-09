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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* fpoint = head;
        ListNode* dpoint = head;
        do {
        	fpoint = fpoint->next;
   			if (dpoint != NULL && dpoint->next != NULL)
        		dpoint = dpoint->next->next;
        } while (dpoint != fpoint);

		if (dpoint == NULL || dpoint->next == NULL) return false;
		else return true;

    }
};
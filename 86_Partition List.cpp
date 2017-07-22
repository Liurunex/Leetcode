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
    ListNode* partition(ListNode* head, int x) {
		ListNode *lesspart     = new ListNode(0);
		ListNode *greaterpart  = new ListNode(0);
		ListNode *dummygreater = greaterpart;
		ListNode *dummyless    = lesspart;
        
        while (head) {
        	if (head->val < x) {
        		lesspart->next = head;
        		lesspart = lesspart->next;
        	}
        	else {
        		greaterpart->next = head;
        		greaterpart = greaterpart->next;
        	}

        	head = head->next;
        }
        
        lesspart->next = dummygreater->next;
        greaterpart->next = 0;
        return dummyless->next;
    }
};

/* Notice: be aware of the end of those list respectively, set the last element to NULL at last */

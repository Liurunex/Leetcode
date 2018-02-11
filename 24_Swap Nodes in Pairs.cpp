class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        while (cur && cur->next) {
            pre->next = cur->next;
            cur->next = pre->next->next;
            pre->next->next = cur;
            pre = cur;
            cur = pre->next;
        }
        return dummy->next;
    }
};

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
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
    ListNode* plusOne(ListNode* head) {
		if (!head) return head;
		ListNode* rhead = head;
		ListNode* pre = NULL;
		while (rhead) {
			ListNode* tem = rhead->next;
			rhead->next = pre;
			pre = rhead;
			rhead = tem;
		}
		
		rhead = pre;
		ListNode* rrhead = rhead;
		int add = 1;
		while (rhead) {
			rhead->val += add;
			if (rhead->val > 9) {
				rhead->val = 0;
				add = 1;
				pre = rhead;
				rhead = rhead->next;
				continue;
			}
			else add = 0;
			
			break;
		}
		if (add) {
			ListNode *newhead = new ListNode(1);
			pre->next = newhead;
		}
		
		pre = NULL;
		while (rrhead) {
			ListNode* tem = rrhead->next;
			rrhead->next = pre;
			pre = rrhead;
			rrhead = tem;
		}

		return pre;
	}
};

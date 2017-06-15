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
	ListNode* oddEvenList(ListNode* head) {
	    if (!head || !head->next) return head;
		ListNode *dummy = NULL;
		ListNode *oddhead = head;
		ListNode *evenhead = NULL;
		int isOdd = 1;
		while (head) {
			if (!evenhead) evenhead = head->next;
			dummy = head->next;
			if (dummy->next) {
				head->next = dummy->next;
				head = dummy;
				isOdd *= -1;
			}
			else {
				if (isOdd == -1) {
					dummy->next = evenhead;
					head->next = NULL;
				}
				else head->next = evenhead;
				break;
			}
		}
		return oddhead;
	}
};

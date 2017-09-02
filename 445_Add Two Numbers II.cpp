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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int len1 = 0, len2 = 0;
		ListNode *dum1 = l1, *dum2 = l2;
		while (dum1) {
			len1 ++;
			dum1 = dum1->next;
		}
		while (dum2) {
			len2 ++;
			dum2 = dum2->next;
		}
		ListNode *dummy = new ListNode(0);
		ListNode *longone  = len1 >= len2 ? l1:l2;
		ListNode *shortone = len1 >= len2 ? l2:l1;

		dummy->next = longone;
		int distance = abs(len1 - len2);
		int counter = 0;
		while (longone) {
			if (counter < distance) {
				counter ++;
				longone = longone->next;
			}
			else {
				longone->val += shortone->val;
				longone       = longone->next;
				shortone      = shortone->next;
			}
		}
		ListNode *twicetravel = dummy;
		ListNode *helper      = dummy->next;
		
		while (helper) {

			if (helper->val > 9) {
				helper->val 	 -= 10;
				while (twicetravel != helper) {
					twicetravel->val += 1;
					twicetravel->val %= 10;
					twicetravel       = twicetravel->next;
				} 
			}

			if (helper->val != 9)
				twicetravel = helper;	
			helper      = helper->next;

		}
		return dummy->val == 0 ? dummy->next:dummy;
	}
};
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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (!head || !head->next) return head;
    	int listsize = 0;
		ListNode* countNode = head;
		while (countNode) {
			countNode = countNode->next;
			listsize ++;
		}
		k %= listsize;

		if (!k) return head;
		ListNode* dummyHead = head;
		for (int i = 0; i < k; ++ i)
			dummyHead = dummyHead->next;
		
		ListNode* newHead = head;
		while (dummyHead->next) {
			dummyHead = dummyHead->next;
			newHead   = newHead->next;
		}

		ListNode* newTail = newHead;
		newHead           = newHead->next;
		newTail->next     = NULL;
			
		dummyHead->next = head;
		return newHead;
	}
};

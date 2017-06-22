/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 *  };
 **/
class Solution {
	public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		ListNode *Adummy = headA;
		ListNode *Bdummy = headB;
		int lenA = 1, lenB = 1;

		while (headA->next) {
			lenA ++;
			headA = headA->next;
		}
		while (headB->next) {
			lenB ++;
			headB = headB->next;
		}

		if (headA != headB) return NULL;
		ListNode *longhead  = lenA >  lenB ? Adummy : Bdummy;
		ListNode *shorthead = lenA <= lenB ? Adummy : Bdummy;
		
		for (int i = 0; i < abs(lenA-lenB); ++ i)
			longhead = longhead->next;
		
		while (longhead != shorthead) {
			longhead  = longhead->next;
			shorthead = shorthead->next;
		}
		return longhead;	
	}
};


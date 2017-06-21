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
    void reorderList(ListNode* head) {
    	if (!head || !head->next) return;
		
		int listSize= 0;
		ListNode *dummy_head = head;
		while (dummy_head) {
			listSize ++;
			dummy_head = dummy_head->next;
		}      

		int split_index = listSize%2 == 0 ? listSize/2-1 : listSize/2;
		
		ListNode *second_part = head;
		for (int i = 0; i < split_index; ++ i)
			second_part = second_part->next;

		ListNode *swap = second_part->next;
		second_part->next = NULL;
		second_part = swap;

		ListNode *reverse_head = NULL;
		while (second_part) {
			ListNode *tem = second_part;
			second_part = second_part->next;
			tem->next = reverse_head;
			reverse_head = tem;
		}
		while (head) { cout << head->val; head = head->next; }
		cout << endl;
		while (reverse_head) { cout << reverse_head->val; reverse_head = reverse_head->next; }
		/*ListNode *first_head = head;
		ListNode *iter = head;
		
		while (reverse_head && first_head) {

			first_head = first_head->next;
			iter->next = reverse_head;
			iter = iter->next;

			reverse_head = reverse_head->next;
			iter->next = first_head;
			iter = iter->next;
	
		}

		if (first_head) 
			iter->next = first_head;
		if (reverse_head)
			iter->next = reverse_head;
	*/
    }
};
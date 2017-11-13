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
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> res;
		int counter = 0;
		ListNode* dummy = root;
		while (dummy) {
			counter ++;
			dummy = dummy->next;
		}

		int k_pre = counter % k;
		int len   = counter / k;
		
		ListNode* head = root;
		res.push_back(root);
		int temlen = 0;
		while (k > 1) {
			k --;
			if (!head) {
				res.push_back(NULL);
			}
			else if (k_pre) {
				for (int i  = 0; i < len; ++ i)
					head = head->next;
				k_pre --;
				ListNode* next = head->next;
				res.push_back(next);
				head->next = NULL;
				head = next;
			}
			else {
				for (int i  = 0; i < len-1; ++ i)
					head = head->next;
				ListNode* next = head->next;
				res.push_back(next);
				head->next = NULL;
				head = next;
			}
		}
		return res;
	}
};
/* the idea: math question: there is n%k sub-lists has n/k+1 nodes, 
 * while the left all sub-list has only n/k nodes!
 */
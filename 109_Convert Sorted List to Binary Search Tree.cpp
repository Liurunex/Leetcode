/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return new TreeNode(head->val);

		ListNode* fast = head, *slow = head, *pre = NULL;
		while (fast && fast->next) {
			pre = slow;
			fast = fast->next->next;
			slow = slow->next;
		}

		pre->next = NULL;
		TreeNode* root = new TreeNode(slow->val);

		root->left = sortedListToBST(head);
		root->right = sortedListToBST(slow->next);

		return root;
 	}
};

/* the idea is similar to 108, we use slow and fast pointer to find the middle node of the whole linkedlist,
 * we also need a pointer to record the node previous to the middle we find and set it as the left half tail
 * so that its next point is NULL; /
 *
 * time complexity is O(nlogn), there is a O(n) method: http://bangbingsyb.blogspot.com/2014/11/leetcode-convert-sorted-list-to-binary.html
 */

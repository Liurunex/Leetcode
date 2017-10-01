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
	int longestUnivaluePath(TreeNode* root) {
		if (!root) return 0;
		int left_path = 0, right_path = 0;
		if (root->left && root->left->val == root->val)
			left_path = findthepath(root->left);
		if (root->right && root->right->val == root->val)
			right_path = findthepath(root->right);
		return max(left_path + right_path, max(longestUnivaluePath(root->left), 
			longestUnivaluePath(root->right)));

	}

	int findthepath(TreeNode* root) {
		if (!root) return 0;
		int left = 0, right = 0;
		if (root->left && root->left->val == root->val)
			left = findthepath(root->left);
		if (root->right && root->right->val == root->val)
			right = findthepath(root->right);
		return max(left, right)+1;
	}
};

/* the idea: we consider three cases, the path pass root, the path pass the left child
 * and the path pass the right child; for each case we use recursive case to count its
 * path length;
 */

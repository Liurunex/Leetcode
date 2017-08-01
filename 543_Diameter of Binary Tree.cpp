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
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root) return 0;
		int left_depth = 0, right_depth = 0;
		if (root->left)
			left_depth = finddepth(root->left);
		if (root->right)
			right_depth = finddepth(root->right);
		return max(left_depth + right_depth, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
	}

	int finddepth(TreeNode* root) {
		if (!root) return 0;
		return max(finddepth(root->left), finddepth(root->right)) + 1;
	}
};

/* notice consider the case longest path might not pass the root */
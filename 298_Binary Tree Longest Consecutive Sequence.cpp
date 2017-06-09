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
	int longestConsecutive(TreeNode* root) {
		if (!root) return 0;
		int res = 1;
		if (root->left)
			res = max(1, helpPreorder(root->left, root, 1));
		if (root->right)
			res = max(res, helpPreorder(root->right, root, 1));
		return res;
	}
	int helpPreorder(TreeNode* node, TreeNode* parent, int p_res) {
		if (!node) return p_res;
		int c_res = 1;
		if (parent->val+1 == node->val)
			c_res = max(p_res+1, max(helpPreorder(node->left, node, p_res+1), helpPreorder(node->right, node, p_res+1)));
		else
			c_res = max(helpPreorder(node->left, node, 1), helpPreorder(node->right, node, 1));
		return c_res;
	}
};

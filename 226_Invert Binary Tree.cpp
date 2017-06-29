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
    TreeNode* invertTree(TreeNode* root) {
    	if (!root) return root;
		stack<TreeNode*> preoreder;
		preoreder.push(root);
		while (!preoreder.empty()) {
			TreeNode *node = preoreder.top();
			preoreder.pop();
			
			TreeNode *tem = node->left;
			node->left = node->right;
			node->right = tem;

			if (node->right) preoreder.push(node->right);
			if (node->left)  preoreder.push(node->left);
		}
		return root;
	}
};

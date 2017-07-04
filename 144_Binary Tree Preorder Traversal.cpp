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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
		vector<int> res;
		stack<TreeNode *> preStack;
		preStack.push(root);
		while (!preStack.empty()) {
			TreeNode *node = preStack.top();
			preStack.pop();
			res.push_back(node->val);

			if (node->right) preStack.push(node->right);
			if (node->left)  preStack.push(node->left);
		}
		return res;
    }
};


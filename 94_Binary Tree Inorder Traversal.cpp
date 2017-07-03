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
    vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> instack;
		vector<int> res;
		TreeNode *cur = root;
		while (1) {
			while (cur) {
				instack.push(cur);
				cur = cur->left;
			}
			if (!instack.empty()) {
				TreeNode *node = instack.top();
				instack.pop();
				res.push_back(node->val);
				cur = node->right;
				continue;
			}
			break;
		}
		return res;
    }
};

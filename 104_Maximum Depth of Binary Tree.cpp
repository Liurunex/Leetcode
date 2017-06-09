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
	int maxDepth(TreeNode* root) {
		stack<pair<TreeNode*, int>> mystack;
		mystack.push(make_pair(root, 0));
		int resmax = 0;
		while (!mystack.empty()) {
			pair<TreeNode*, int> nodepair = mystack.top();
			mystack.pop();
			if (nodepair.first->right)
				mystack.push(make_pair(nodepair.first->right, nodepair.second);
			if (nodepair.first->left)
				mystack.push(make_pair(nodepair.first->left, nodepair.second);
			if (!nodepair.first->left || !nodepair.first->right)
				resmax = max(resmax, nodepair.second);
		}
		return resmax;
	}
};

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
	int findBottomLeftValue(TreeNode* root) {
		if (!root) return 0;
		int leftmost = root->val;
		queue<pair<TreeNode*, int>> dfsqueue;
		dfsqueue.push(make_pair(root, 0));
		while (!dfsqueue.empty()) {
			pair<TreeNode*, int> node = dfsqueue.front();
			dfsqueue.pop();

			if (node.first->left) {
				leftmost = node.first->left->val;
				dfsqueue.push(make_pair(node.first->left, node.second+1));
			}
			if (node.first->right) 
				dfsqueue.push(make_pair(node.first->right, node.second+1));
		}
		return leftmost;
	}
};
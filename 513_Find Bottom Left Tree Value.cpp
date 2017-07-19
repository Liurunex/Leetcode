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
		queue<pair<TreeNode*, int>> dfsqueue;
		dfsqueue.push(make_pair(root, 0));
		pair<TreeNode*, int> levelnode;
		levelnode.first = root;
		levelnode.second = 0;
		while (!dfsqueue.empty()) {
			pair<TreeNode*, int> node = dfsqueue.front();
			dfsqueue.pop();
			
			if (levelnode.second < node.second) {
				levelnode.first = node.first;
				levelnode.second = node.second;
			}

			if (node.first->left) {
				dfsqueue.push(make_pair(node.first->left, node.second+1));
			}
			if (node.first->right)
				dfsqueue.push(make_pair(node.first->right, node.second+1));
		}
		return levelnode.first->val;
	}
};

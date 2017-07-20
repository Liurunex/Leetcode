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
	vector<int> largestValues(TreeNode* root) {
		if (!root) return {};
		vector<int> res;
		int curRow = 0;
		queue<pair<TreeNode*, int>> bfsqueue;
		bfsqueue.push(make_pair(root, 0));
		while (!bfsqueue.empty()) {
			pair<TreeNode *, int> node = bfsqueue.front();
			bfsqueue.pop();

			if (res.empty())
				res.push_back(node.first->val);
			else {
				if (curRow == node.second)
					res.back() = max(res.back(), node.first->val);
				else {
					res.push_back(node.first->val);
					curRow = node.second;
				}
			}

			if (node.first->left) bfsqueue.push(make_pair(node.first->left, node.second+1));
			if (node.first->right) bfsqueue.push(make_pair(node.first->right, node.second+1));
		}

		return res;
	}
};
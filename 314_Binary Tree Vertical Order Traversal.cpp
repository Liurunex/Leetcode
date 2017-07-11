/* NOTICE: using BFS not DFS */
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
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>>	res;
		if (!root) return res;
		map<int, vector<int>> colDic;
		queue<pair<TreeNode*, int>> traversalStack;
		
		traversalStack.push(make_pair(root, 0));
		while (!traversalStack.empty()) {
			pair<TreeNode*, int> node = traversalStack.front();
			traversalStack.pop();
			if (colDic.find(node.second) == colDic.end()) {
				vector<int> newcol;
				newcol.push_back(node.first->val);
				colDic[node.second] = newcol;
			}
			else colDic[node.second].push_back(node.first->val);

			if (node.first->left)
				traversalStack.push(make_pair(node.first->left, node.second-1));
			if (node.first->right)
				traversalStack.push(make_pair(node.first->right, node.second+1));
		}

		
		for (auto i = colDic.begin(); i != colDic.end(); ++ i) 
			res.push_back(i->second);
		return res;
	}
};
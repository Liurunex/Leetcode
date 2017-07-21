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
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return {};
		vector<string> res;
		vector<pair<TreeNode *, int>> path_record;
		stack<pair<TreeNode *, int>> dfsstack;
		dfsstack.push(make_pair(root, 0));
		while (!dfsstack.empty()) {
			pair<TreeNode *, int> node = dfsstack.top();
			dfsstack.pop();

			while (!path_record.empty() && node.second != path_record.back().second+1)
				path_record.pop_back();
			
			path_record.push_back(node);

			if (!node.first->left && !node.first->right)
				res.push_back(printhelp(path_record));
			
			
			
			if (node.first->right) dfsstack.push(make_pair(node.first->right, node.second+1));
			if (node.first->left) dfsstack.push(make_pair(node.first->left, node.second+1));
		}
		return res;
	}

	string printhelp(vector<pair<TreeNode *, int>> path_record) {
		string path;
		for (int i = 0; i < path_record.size(); ++ i)
			path += to_string(path_record[i].first->val) + "->";
		path.pop_back();
		path.pop_back();
		return path;
	}
};
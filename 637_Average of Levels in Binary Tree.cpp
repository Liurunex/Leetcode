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
	vector<double> averageOfLevels(TreeNode* root) {
		if (!root) return {};
		queue<pair<TreeNode*, int>> bfsqueue;
		vector<double> res;
		vector<int> res_counter;
		bfsqueue.push(make_pair(root, 0));
		while (!bfsqueue.empty()) {
			pair<TreeNode*, int> node = bfsqueue.front();
			bfsqueue.pop();
			if (node.second >= res.size()) {
				res.push_back(node.first->val);
				res_counter.push_back(1);
			}
			else {
				res_counter[node.second] ++;
				res[node.second] += node.first->val;
			}

			if (node.first->left)
				bfsqueue.push(make_pair(node.first->left, node.second+1));
			if (node.first->right)
				bfsqueue.push(make_pair(node.first->right, node.second+1));
		} 

		for (int i = 0; i < res.size(); ++ i)
			res[i] /= res_counter[i];
		
		return res;
	}
};
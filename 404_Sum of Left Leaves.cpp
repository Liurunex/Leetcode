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
    int sumOfLeftLeaves(TreeNode* root) {
    	if (!root) return 0;
     	stack<pair<TreeNode *, int>> dfsstack;
		dfsstack.push(make_pair(root, 0));
		vector<int> leaves;
		while (!dfsstack.empty()) {
			pair<TreeNode *, int> node = dfsstack.top();
			dfsstack.pop();

			if (!node.first->right && !node.first->left && node.second)
				leaves.push_back(node.first->val);

			if (node.first->right) dfsstack.push(make_pair(node.first->right, 0));
			if (node.first->left)  dfsstack.push(make_pair(node.first->left, 1));
		} 
		int res = 0;
		for (int i = 0; i < leaves.size(); ++ i)
			res += leaves[i];
		return res;
    }
};
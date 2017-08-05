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
private:
	int res = 0;
public:
	int closestValue(TreeNode* root, double target) {
		return help(root, target).second;
	}

	pair<double, int> help(TreeNode* root, double target) {
		if (!root) return make_pair(-1,0);
		double dis_cur = abs(root->val - target);
		TreeNode* checksub = target > root->val ? root->right:root->left;
		auto sub = help(checksub, target);
		if (sub.first == -1 || sub.first > dis_cur) return make_pair(dis_cur, root->val);
		return sub;
	}
};
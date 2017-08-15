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
	bool findTarget(TreeNode* root, int k) {
		return help(root, k, 0);
	}
	bool help(TreeNode* root, int k, int t) {
		if (!root) return k == 0 && t == 2;
		int res = k - root->val;
		if (!res) return t == 1;
		
        bool ans = false;
		if (res < root->val)
			ans = ans || help(root->left, res, t+1);
		else 
			ans = ans || help(root->right, res, t+1);
		
			ans = ans || help(root->left, k, t) || help(root->right, k, t);
		
		return ans;
	}
};
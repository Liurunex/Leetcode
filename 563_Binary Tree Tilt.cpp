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
	int findTilt(TreeNode* root) {
		helper(root);
		return res;
	}
	int helper(TreeNode* root) {
		if (!root) return 0;
		int leftsum = helper(root->left);
		int righsum = helper(root->right);
		res += abs(leftsum-righsum);
		return leftsum + righsum + root->val;
	}
};
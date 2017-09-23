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
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		int left_root  = pathSum(root->left, sum);
		int right_root = pathSum(root->right, sum);
		int itself     = helperdfs(root, sum, 0);
		return left_root + right_root + itself;
	}

	int helperdfs(TreeNode* node, int& target, int cursum) {
		if (!node) return 0;
		int sum = cursum + node->val;
		return (sum == target ? 1:0) + 
		helperdfs(node->left, target, sum) + helperdfs(node->right, target, sum);
	}

};
/* the idea: just do dfs to all subtree, that is we make dfs on both of left and right subtrees,
 * and sum them up
 */

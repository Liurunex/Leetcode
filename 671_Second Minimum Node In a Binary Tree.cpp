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
	int res = -1, small = -1, first = 1;
	int findSecondMinimumValue(TreeNode* root) {
		if (!root) return -1;
		TreeNode* next = NULL;
		if (first) { first = 0; small = root->val; res = small; }
		if (!root->left) return res == small ? -1:res;

		if (root->left->val != root->right->val){
			int candiate = max(root->left->val, root->right->val);
			next = root->left->val > root->right->val ? root->right:root->left;
			res = small == res ? candiate:min(candiate, res);
			return findSecondMinimumValue(next);
		}
		else {
			int left_res = findSecondMinimumValue(root->left);
			int right_res = findSecondMinimumValue(root->right);
			if (left_res == -1) return right_res;
			else if (right_res == -1) return left_res;
			else return min(left_res, right_res);
		}
	}
};
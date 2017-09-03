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
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		TreeNode* res = NULL;
		if (!root) return NULL;
		if (root->val > R) return trimBST(root->left, L, R);
		if (root->val < L) return trimBST(root->right, L, R);

		helpTrim(root->left, root, 1, L, R);
		helpTrim(root->right, root, 0, L, R);

		return root;
	}

	void helpTrim(TreeNode* root, TreeNode* pre, int isleft, int L, int R) {
		if (!root) return;
		if (root->val <= R && root->val >= L) {
			helpTrim(root->left, root, 1, L, R);
			helpTrim(root->right, root, 0, L, R);
			return;
		}
		else if (root->val > R) {
			if (isleft) pre->left = root->left;
			else pre->right = root->left;
			root->left = NULL;
			//deleteTree(root);
			TreeNode* next = isleft ? pre->left:pre->right;
			helpTrim(next, pre, isleft, L, R);
		}
		else if (root->val < L) {
			if (isleft) pre->left = root->right;
			else pre->right = root->right;
			root->right = NULL;
			//deleteTree(root);
			TreeNode* next = isleft ? pre->left:pre->right;
			helpTrim(next, pre, isleft, L, R);
		}
	}
};
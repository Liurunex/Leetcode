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
	int getMinimumDifference(TreeNode* root) {
		int res = INT_MAX, pre = -1;
		inorder(root, res, pre);
		return res;
	}

	void inorder(TreeNode* root, int& res, int& pre) {
		if (!root) return;

		inorder(root->left, res, pre);
		if (pre != -1) res = min(res, abs(pre-root->val));
		pre = root->val;
		inorder(root->right, res, pre);
	}
};

/*
the idea: we use the inorder traversal to traversal which will generate a 
sorted array, then our goal is to find the minmum difference between adjacent
elements
 */
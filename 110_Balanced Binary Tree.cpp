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
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		int left = depthFind(root->left);
		int right = depthFind(root->right);

		return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}

	int depthFind (TreeNode* root) {
		if (!root) return 0;
		return 1 + max(depthFind(root->left), depthFind(root->right));
	}
};

/* the idea: brute force: check each node for its subtree's depth difference, check each node for
 * calculate the detpht with O(logn), total time complecity is O(nlogn)
 */

/* better idea: once we find a node is unbalanced, we just return -1 as sign of non-balanced, so that
 * avoid meaningless and duplicate calculation */
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		return depthFind(root) != -1;
	}

	int depthFind (TreeNode* root) {
		if (!root) return 0;
		
		int left = depthFind(root->left);
		if (left == -1) return -1;
		int right = depthFind(root->right);
		if (right == -1) return -1;
		
		return abs(left-right) > 1 ? -1 : 1+max(left, right);

	}
};
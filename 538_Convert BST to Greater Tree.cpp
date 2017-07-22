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
	int pre_sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
		if (!root) return NULL;
		sumupTravel(root);
		return root;
    }

    void sumupTravel(TreeNode* root) {
    	if (root->right) sumupTravel(root->right);
    	pre_sum   += root->val;
		root->val  = pre_sum;
		if (root->left)  sumupTravel(root->left);
    }

};

/* the idea is to convert inorder traversal to right->root->left */
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return NULL;
		if (root == p || root == q) return root;
		TreeNode* left_subTree = lowestCommonAncestor(root->left, p, q);
		TreeNode* right_subTree = lowestCommonAncestor(root->right, p, q);

		if (left_subTree && right_subTree) return root;

		return left_subTree ? left_subTree:right_subTree;
	}
};

/* 	the idea is: if a node is LCA, then both of its left and right tree
	should marked, that is, if only its left or right subtree was marked,
	the LCA should belong to that side, otherwise, the descents of current
	node don't contain neither of p or q
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root;
        return left ? left:right;
        
    }
};
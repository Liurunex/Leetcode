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
        TreeNode* big = p->val > q->val ? p:q;
        TreeNode* sam = p->val > q->val ? q:p;
        if (root->val >= sam->val && root->val <= big->val) return root;
        if (root->val < sam->val) return lowestCommonAncestor(root->right, p, q);
    	if (root->val > big->val) return lowestCommonAncestor(root->left, p, q);
    }
};
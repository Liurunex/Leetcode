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
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MAX;
        TreeNode* pre = NULL;
        inorder(root, res, pre);
        return res;
    }
    
    void inorder(TreeNode* root, int& res, TreeNode* &pre) {
        if (!root) return;
        inorder(root->left, res, pre);
        if (!pre)
            pre = root;
        else {
            res = min(res, abs(pre->val-root->val));
            pre = root;
        }
        inorder(root->right, res, pre);
    }
};
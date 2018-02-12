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
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    
    bool helper(TreeNode* node, TreeNode* left_min, TreeNode* right_max) {
        if (!node) return true;
        if (left_min && left_min->val >= node->val) return false;
        if (right_max && right_max->val <= node->val) return false;
        return helper(node->left, left_min, node) && helper(node->right, node, right_max);
    }
};
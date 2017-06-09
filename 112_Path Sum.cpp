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
    bool hasPathSum(TreeNode* root, int sum) {
        int o = sum;
        if (root == NULL) return false;
        sum -= root->val;
        if (root->left == NULL && root->right == NULL && sum == 0) return true;

        bool res = false;
        if (root->left != NULL) {
            res = hasPathSum(root->left, sum);
            if (res) return res;
        }
        if (root->right != NULL)
            res = hasPathSum(root->right, sum);
        return res;
    }
};
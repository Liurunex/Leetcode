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
    int countNodes(TreeNode* root) {
        int lheight = 0, rheight = 0;
        TreeNode* tem = root;
        
        while (tem != NULL) {
        	lheight ++;
        	tem = tem->left;
        }

        tem = root;
        while (tem != NULL) {
        	rheight ++;
        	tem = tem->right;
        }

        if (lheight == rheight) 
        	return (1 << lheight) - 1;
       	return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
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
		return help(root, NULL, NULL);    
    }

    bool help(TreeNode* root, TreeNode* minnode, TreeNode* maxnode) {
    	if (!root)
    		return true;
    	if (minnode != NULL && minnode->val > root->val)
    		return false;
    	if (maxnode != NULL && maxnode->val < root->val)
    		return false;
    	return help(root->left, minnode, root) && help(root->right, root, maxnode);
    }
};
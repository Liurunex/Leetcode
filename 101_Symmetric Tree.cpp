/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* Recursive Solution: 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return HelpSymm(root->left, root->right);
    }

    bool HelpSymm(TreeNode* p1, TreeNode* p2) {
    	if (p1 == NULL && p2 == NULL)
    		return true;
    	if (p1 == NULL || p2 == NULL)
    	    return false;
    	if (p1->val == p2->val)
    		return HelpSymm(p1->left, p2->right) && HelpSymm(p1->right, p2->left);
    	return false;
    }
};
*/
/* Iterator Solution: */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
    }
};
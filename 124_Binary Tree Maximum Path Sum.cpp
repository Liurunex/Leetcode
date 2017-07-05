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
    int maxPathSum(TreeNode* root) {
    	if (!root) return 0;
		int res = root->val;
		int useless = recurMax(res, root);
		return res;
    }

	int recurMax(int &res, TreeNode *node) {
		if (!node) return 0;
		int leftMax          = max(0, recurMax(res, node->left ));
		int rightMax         = max(0, recurMax(res, node->right));
		
		int itsMax = leftMax + rightMax + node->val;
		res = max(itsMax, res);
		int returnMax = max(node->val+leftMax, node->val+rightMax);
		return returnMax;
	}
};

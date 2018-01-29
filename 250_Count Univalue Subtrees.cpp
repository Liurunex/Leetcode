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
	int countUnivalSubtrees(TreeNode* root) {
		int res = 0;
		preTravel(root, res);
		return res;
	}

	bool preTravel(TreeNode* root, int& res) {
		if (!root) return 1;
		if (!root->left && !root->right) {
			res ++;
			return 1;
		}
		
		bool left_uni  = preTravel(root->left, res);
		bool right_uni = preTravel(root->right, res);
		
		if (root->left && root->right && root->left->val != root->right->val)
			return 0;
		
		int unival = root->left ? root->left->val:root->right->val;
		if (left_uni && right_uni && root->val == unival) {
			res ++;
			return 1;
		}
		return 0;
	}
};

/* The idea: recursive call，preorder遍历一遍，对于一个节点，返回左右subtree是不是uni的，
 * 然后可确定自己是不是，最后返回给 parent。 NOTICE: 对于左右subtree有空的情况要看看，否则
 * access null pointer!
 */
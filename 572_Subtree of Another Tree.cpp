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
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!t || !s) return false;
		bool res = false;
		if (s->val == t->val)
			res = testSubtree(s, t);
		if (res) return true;
		res = isSubtree(s->left, t) || isSubtree(s->right, t);
		return res;
	}

	bool testSubtree(TreeNode* s, TreeNode* t) {
		if (!s && !t) return true;
		if ((!s && t) || (s && !t)) return false;
		if (s->val == t->val)
			return testSubtree(s->left, t->left) && testSubtree(s->right, t->right);
		return false;
	}
};

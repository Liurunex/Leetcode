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
	string tree2str(TreeNode* t) {
		string res;
		helper(t, res);
		return res;
	}

	TreeNode* helper(TreeNode* t, string& res) {
		if (!t) return NULL;
		res += to_string(t->val);
		TreeNode* left = NULL;
		TreeNode* right = NULL;
		
		res += "(";
		left = helper(t->left, res);
		res += ")(";
		right = helper(t->right, res);
		if (right)
			res += ")";
		else if (left)
			res.pop_back();
		else {
			res.pop_back();
			res.pop_back();
			res.pop_back();
		}
		return t;
	}
};
/* the idea: simply a dfs problem, what we need to consider is the cases: if both left and
 * right children are null, then no parenthesis added, otherwise left always need
 * parenthesis, but right is depending on if it's empty;
 */
class Solution{
public:
  string tree2str(TreeNode* t) {
        if (t == NULL) return "";
        string s = to_string(t->val);
        if (t->left) s += '(' + tree2str(t->left) + ')';
        else if (t->right) s += "()";
        if (t->right) s += '(' + tree2str(t->right) + ')';
        return s;
    }
};

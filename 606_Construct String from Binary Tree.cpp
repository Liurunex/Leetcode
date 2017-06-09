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
		if (!t) return res;
		stack<pair<TreeNode *, int>> myStack;
		myStack.push(make_pair(t, 0));
		while (!myStack.empty()) {
			if (myStack.top().second == 1) {
				res += "(";
				myStack.pop();
				continue;
			}
			if (myStack.top().second == 2) {
				res += ")";
				myStack.pop();
				continue;
			}
			TreeNode* node = myStack.top().first;
			myStack.pop();
			res += to_string(node->val);
			if (!node->right && !node->left)
			    continue;
			if (node->right) {
			    myStack.push(make_pair(t, 2));
			    myStack.push(make_pair(node->right, 0));
			    myStack.push(make_pair(t, 1));
			}
			if (node->left) {
			    myStack.push(make_pair(t, 2));
			    myStack.push(make_pair(node->left, 0));
			    myStack.push(make_pair(t, 1));
			}
			else res += "()";
		}
		return res;
	}
};

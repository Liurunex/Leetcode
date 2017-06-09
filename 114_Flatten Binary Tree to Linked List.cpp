/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* preorder solution is slow */
class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root) return;
		vector<TreeNode*> record;
		Mypreorder(root, record);
		for (int i = 0; i < record.size()-1; ++ i) {
			record[i]->left = NULL;
			record[i]->right = record[i+1];
		}
	}
	void Mypreorder(TreeNode* root, vector<TreeNode*> &record) {
		if (!root) return;
		stack<TreeNode*> tstack;
		tstack.push(root);
		while (!tstack.empty()) {
			TreeNode* cur = tstack.top();
			tstack.pop();
			record.push_back(cur);
			if (cur->right) tstack.push(cur->right);
			if (cur->left) tstack.push(cur->left);
		}
	}
};
/* directly construct flattened subtree*/
class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root) return;
		helpflatten(root);
	}
	TreeNode* helpflatten(TreeNode* node) {
		if (!node) return NULL;
		TreeNode* leftTail = helpflatten(node->left);
		TreeNode* rightTail = helpflatten(node->right);
		/* if left child not empty, flatten it */
		if (node->left) {
			leftTail->right = node->right;
			node->right = node->left;
			node->left = NULL;
		}
		/* if right tail is not NULL*/
		if (rightTail) return rightTail;
		if (leftTail) return leftTail;
		/* both children are NULL */
		return node;
	}
};

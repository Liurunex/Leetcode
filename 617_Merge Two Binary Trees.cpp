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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1) return t2;
		if (!t2) return t1;
		stack<pair<TreeNode*, TreeNode*>> trstack;
		trstack.push(make_pair(t1, t2));
		while (!trstack.empty()) {
			pair<TreeNode*, TreeNode*> node = trstack.top();
			trstack.pop();
			
			node.first->val += node.second->val;

			if ((node.first && node.first->right) || (node.second && node.second->right)) { 
				node.first->right = node.first->right ? node.first->right : new TreeNode(0);
				node.second->right = node.second->right ? node.second->right : new TreeNode(0);
				trstack.push(make_pair(node.first->right, node.second->right));
			}
	
			if ((node.first && node.first->left) || (node.second && node.second->left)) {
				node.first->left = node.first->left ? node.first->left : new TreeNode(0);
				node.second->left = node.second->left ? node.second->left : new TreeNode(0);
				trstack.push(make_pair(node.first->left, node.second->left));
			}
		}
		return t1;
	}
};
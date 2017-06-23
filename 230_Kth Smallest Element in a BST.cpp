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
    int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> treeStack;
		TreeNode* current = root;	
		int cindex = 0;
		while (1) {
			while (current) {
				treeStack.push(current);
				current = current->left;
			}
			if (!treeStack.empty()) {
				TreeNode* node = treeStack.top();
				treeStack.pop();
				cindex ++;
				
				if (cindex == k) return node->val;
				current = node->right;
				continue;
			}
			break;
		}
		return -1;
	}
};

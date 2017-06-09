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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == NULL) 
            return vector<vector<int> > ();
		vector<vector<int>> res;
		vector<int> level;

		stack<TreeNode*> mystack;
		stack<TreeNode*> newstack;
		mystack.push(root);
		addlevel(res, level, mystack, newstack, 1);
		return res;    
    }

    void addlevel(vector<vector<int>>& res, vector<int> level, 
    	stack<TreeNode*> mystack, stack<TreeNode*> newstack, int direction) {
    	
    	while (!mystack.empty()) {
			TreeNode* node = mystack.top();
			mystack.pop();
			level.push_back(node->val);
			if (direction == 1) {
				if (node->left != NULL) 
					newstack.push(node->left);	
				if (node->right != NULL)
					newstack.push(node->right);
			}
			else {
				if (node->right != NULL)
					newstack.push(node->right);	
				if (node->left != NULL)
					newstack.push(node->left);
			}
		}
		res.push_back(level);
		level.clear();
		direction *= -1;
		if (!newstack.empty())
			addlevel(res, level, newstack, mystack, direction);
    }
};
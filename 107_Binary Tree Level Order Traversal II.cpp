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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) 
            return vector<vector<int> > ();
		vector<vector<int>> output;
		stack<vector<int>> res;
		vector<int> level;
		queue<TreeNode*> myqueue;
		myqueue.push(root);
		int size = 1;

		while (!myqueue.empty()) {
			if (size == 0) {
				res.push(level);
				level.clear();
				size = myqueue.size();
			}
			TreeNode* node = myqueue.front();
			myqueue.pop();
			size --;
			level.push_back(node->val);
			if (node->left != NULL)
				myqueue.push(node->left);
			if (node->right != NULL)
				myqueue.push(node->right);
		}
        output.push_back(level);
		while (!res.empty()) {
			output.push_back(res.top());
			res.pop();
		}
		return output;
    }
};
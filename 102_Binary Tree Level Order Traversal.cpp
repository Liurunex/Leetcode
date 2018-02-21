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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) 
            return vector<vector<int> > ();
		vector<vector<int>> res;
		vector<int> level;
		queue<TreeNode*> myqueue;
		myqueue.push(root);
		int size = 1;

		while (!myqueue.empty()) {
			if (size == 0) {
				res.push_back(level);
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
        res.push_back(level);
		return res;
    }
};
// recursion solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res, 0);
        return res;
    }
    
    void helper(TreeNode* node, vector<vector<int>>& res, int level) {
        if (!node) return;
        if (res.size() == level)
            res.push_back({});
        res[level].push_back(node->val);
        helper(node->left, res, level+1);
        helper(node->right, res, level+1);
    }
};
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
	vector<vector<int>> findLeaves(TreeNode* root) {
		if (!root) return {};
		vector<vector<int>> res;
		dfs_helper(root, res);
		return res;
 	}

 	int dfs_helper(TreeNode* root, vector<vector<int>>& res) {
 		if (!root) return 0;
 		int height = max(dfs_helper(root->left, res), dfs_helper(root->right, res)) + 1;
 		if (height > res.size())
 			res.push_back(vector<int> (1, root->val));
 		else res[height-1].push_back(root->val);
 		return height;
 	}
};

/*
the idea is compute height by recursive ways, try to come up a 
iteration way
 */

/* quesion: why the follwoing is 3ms fast*/
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, vector<vector<int>>& res) {
        if (!root) return 0;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        int height = 1 + max(left, right);
        if (height - 1 == res.size()) res.push_back({});
        res[height-1].push_back(root->val);
        return height;
    }
};
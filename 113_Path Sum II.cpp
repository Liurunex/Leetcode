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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	if (!root) return {};
    	vector<vector<int>> res;
    	vector<int> candiate;
    	dfs_helper(root, candiate, res, 0, sum); 
    	return res;  
    }

    void dfs_helper(TreeNode* root, vector<int>& candiate,
    	vector<vector<int>>& res, int pre_sum, int target) {
    	if (!root) {
    		if (pre_sum == target) res.push_back(candiate); 
    		return;
    	}

    	int sum = pre_sum + root->val;
    	//
		candiate.push_back(root->val);
		if (!root->left && !root->right) dfs_helper(NULL, candiate, res, sum, target);
		if (root->left)  dfs_helper(root->left,  candiate, res, sum, target);
		if (root->right) dfs_helper(root->right, candiate, res, sum, target);
		candiate.pop_back();
    	
    }
};

/*
a trick: you must consider negative value case: that is if (sum <= target) is not reasonable
 */
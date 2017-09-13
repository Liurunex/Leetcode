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
	bool checkEqualTree(TreeNode* root) {
		int totalsum = 0;
		unordered_map<int, int> subtree_sum;
		checkSum(root, root, totalsum, subtree_sum);
		return (!(totalsum%2) && 
			subtree_sum.find(totalsum/2) != subtree_sum.end());
	}

	int checkSum(TreeNode* root, TreeNode* boss, int& totalsum, 
		unordered_map<int, int>& subtree_sum) {
		if (!root)
			return 0;
		
		totalsum += root->val;
		
		int subleft  = checkSum(root->left, boss, totalsum, subtree_sum);
		int subright = checkSum(root->right, boss, totalsum, subtree_sum);
		int sum = root->val + subright + subleft;
		if (root != boss)
			subtree_sum[sum] ++;
		return sum;
	}
};

/* the idea is we keep computing the subtree tree's sum and push it into
 * a hashmap, meanwhile we also keep recording the total sum started from
 * root, our goal is to find if the hashtable contain the half value of
 * total_sum;
 * the trick is be NOTICED not to add the total sum into the hashtable,
 * otherwise we cannot handle the case where total sum eqaul its half value
 * which is zero case
 */

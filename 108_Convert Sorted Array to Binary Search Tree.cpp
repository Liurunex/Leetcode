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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (!nums.size()) return NULL;
		if (nums.size() == 1) return new TreeNode(nums[0]);

		TreeNode* root = new TreeNode(nums[nums.size()/2]);
		
		vector<int> leftside (nums.begin(), nums.begin()+nums.size()/2);
		vector<int> rightside (nums.begin()+nums.size()/2+1, nums.end());
		
		root->left = sortedArrayToBST(leftside);
		root->right = sortedArrayToBST(rightside);

		return root;
	}
};

/* the idea is simple: we know that a inorder traversal operating on a 
 * binary search tree will result in a asecendig sorted array; based on
 * this, we can indiate that for a asceding sorted array, the middle 
 * node is definetely the root of the tree, and the left node will be
 * the middle of left subarray, the right node will be the middle of 
 * right subarray.
 */

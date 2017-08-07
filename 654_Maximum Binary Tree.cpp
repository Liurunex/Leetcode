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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		int maxindex = 0;
		for (int i = 1; i < nums.size(); ++ i)
			if (nums[i] >= nums[maxindex])
				maxindex = i;
		cout << "index: " << maxindex << endl;
		
		TreeNode* root = new TreeNode(nums[maxindex]);
		TreeNode* parent = NULL;
		for (int i = 0; i < maxindex; ++ i) {
			if (!root->left) {
                root->left = new TreeNode(nums[i]);
                parent = root->left;
                continue;
            }
            parent->
           	
        }
        
		for (int i = nums.size()-1; i > maxindex; -- i) {
			if (!root->right) {
                root->right = new TreeNode(nums[i]);
                continue;
            }
            root->right = bstinsert(root->right, nums[i]);
        }
		return root;
	}

	TreeNode* bstinsert(TreeNode* root, int val) {
		if (!root)
			root = new TreeNode(val);
		else if (val > root->val) 
			root->right = bstinsert(root->right, val);
		else 
			root->left = bstinsert(root->left, val);
		return root;
	}
};
// left and right boundary 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = left+(right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid-1);
        root->right = helper(nums, mid+1, right);
        return root;
    }
};

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

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
private:

public:
	int largestBSTSubtree(TreeNode* root) {
		int res = 0, this_left_max = INT_MIN, this_right_min = INT_MAX;
		validBSThelper(root, res, this_right_min, this_left_max);
		return res;
	}

	bool validBSThelper(TreeNode* node, int& res, int& this_right_min, int& this_left_max) {
		if (!node) return true;

		int left_BST_size = 0, right_BST_size = 0;
		int left_min = INT_MAX, left_max = INT_MIN, right_min = INT_MAX, right_max = INT_MIN;

		bool left_BST  = validBSThelper(node->left, left_BST_size, left_min, left_max);
		bool right_BST = validBSThelper(node->right, right_BST_size, right_min, right_max);

		if (left_BST && right_BST) {
			if (node->val < right_min && node->val > left_max) {
				res = left_BST_size + right_BST_size + 1;
				this_right_min = node->left ? left_min:node->val;
				this_left_max = node->right ? right_max:node->val;
				return true;
			}
			else {
				res = max(left_BST_size, right_BST_size);
				return false;
			}
		}
		/* this is a trick: if you do follow, you will alaways get 0 at root
		if (!left_BST && !right_BST) return res;
		res = left_BST ? left_BST_size:right_BST_size;
		*/
		res = max(left_BST_size, right_BST_size);
		return false;
	}
};

/* the idea: consider about "check BST question", here we use the similar thoughts. The 
 * core idea is to do a bottom up traversal with recording the left_max and right_min, 
 * and update longest subtree size; the detail process for the recursive function is:
 * we inital the max_bst_number, min and max value for its left and right subtree
 * respectively, check if the left/right subtree is BST; if so check if current node with
 * its left and right subtree forming a BST, only in this case we should update the
 * boudary of its min and max (otherwise it is the inital value INT_MAX and INT_MIN, no
 * need for updating); other cases will be treated as the false case, what we need to do
 * is update the max BST size in case some of its subtrees are BST
 * take a look here:
 * http://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
 * /

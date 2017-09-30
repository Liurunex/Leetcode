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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() != inorder.size()) return NULL;
		TreeNode *root = buildTreeHelper(preorder, inorder, 
			0, 0, inorder.size()-1);
		return root;
	}

	TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
		int p_start, int i_start, int i_end) {
		
		if (p_start < 0 || p_start >= preorder.size() || i_start > i_end) return NULL;
		
		TreeNode* node = new TreeNode(preorder[p_start]);
		
		int root_index = -1;
		for (int i = i_start; i <= i_end; i ++) {
			if (preorder[p_start] == inorder[i]) {
				root_index = i;
				break;
			}
		}
		//if (root_index == -1) return NULL;

		node->left  = buildTreeHelper(preorder, inorder, p_start+1,
			i_start, root_index-1);

		node->right = buildTreeHelper(preorder, inorder, p_start+1 + (root_index-i_start),
			root_index+1, i_end);

		return node;
	}
};
/* the idea: top-down, the root in preorder traversal is the first element, while is the mid element in
 * inorder traversal, so as both of its left and right subtree; our thought is using recursive
 * way, build the current root, divide the inorder list into left subtree and right subtree,
 * then recursively call the function to build the left and right subtree;
 * the trick: we don't need pass the sub-preorder start and end position, since think about how we build
 * the tree, that is we always build the left tree first, so that once we start build the right subtree
 * keep increasing the preorder start index will automatically equal to the right subtree root we want,
 * so that we could just pass a reference to increase the perfermance
 */

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() != inorder.size()) return NULL;
        int root_val = 0;
		TreeNode *root = buildTreeHelper(preorder, inorder, 
			root_val, 0, inorder.size()-1);
		return root;
	}

	TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
		int& p_start, int i_start, int i_end) {
		
		if (i_start > i_end) return NULL;
		
		TreeNode* node = new TreeNode(preorder[p_start]);
		
		int root_index = -1;
		for (int i = i_start; i <= i_end; i ++) {
			if (preorder[p_start] == inorder[i]) {
				root_index = i;
				break;
			}
		}

        p_start ++;
		node->left  = buildTreeHelper(preorder, inorder, p_start,
			i_start, root_index-1);

		node->right = buildTreeHelper(preorder, inorder, p_start,
			root_index+1, i_end);

		return node;
	}
};

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	if (postorder.size() != inorder.size()) return NULL;
        int index = postorder.size()-1;
        TreeNode *root = buildTreeHelper(inorder, postorder, index, 0, index);
        return root;
    }

	TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, 
		int& p_end, int i_start, int i_end) {

    	if (i_start > i_end) return NULL;

    	TreeNode* node = new TreeNode(postorder[p_end]);

    	int root_index = -1;
    	for (int i = i_start; i <= i_end; ++ i) {
    		if (postorder[p_end] == inorder[i]) {
    			root_index = i;
    			break;
    		}
    	}
    	
    	p_end --;

    	node->right = buildTreeHelper(inorder, postorder, p_end,
    		root_index+1 ,i_end);
    	node->left  = buildTreeHelper(inorder, postorder, p_end,
    		i_start, root_index-1);

    	return node;
    }
};

/* the idea: just same as 105, the only difference is the root should be the last element of postorder list,
 * namely, instead of building the tree from left to right, we should go from right subtree and then left
 */

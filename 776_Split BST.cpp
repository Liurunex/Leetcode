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
	vector<TreeNode*> splitBST(TreeNode* root, int V) {
		TreeNode* parent = NULL;
		int lr = -1;
		TreeNode* node = findKey(root, V, lr, parent);
		// not found key
		if (!node) return {root, NULL};
		// key has no parent
		if (node == root) {
			TreeNode* split = node->right;
			node->right = NULL;
			return {node, split};
		}
		// key has parent
        cout << node->val << " " << parent->val << endl;
		TreeNode* larger = node->right;
		node->right = NULL;
		if (lr) parent->right = larger;
		else parent->left = larger;
		return {root, node};
	}

	TreeNode* findKey(TreeNode* node, int& V, int& lr, TreeNode*& parent) {
		if (!node) return NULL;
		if (node->left && node->left->val == V) {
			lr = 0;
			parent = node;
			return node->left;
		}
		if (node->right && node->right->val == V) {
			lr = 1;
			parent = node;
			return node->right;
		}
		if (node->val > V)
			return findKey(node->left, V, lr, parent);
		else return findKey(node->right, V, lr, parent);
	}
};

/* the idea: BST.bst search的过程中记录其parent和是左右树，recursion结束后看parent和target是不是null来判断返回.
 * NOTICE: 传pointer进function并希望改变其值的时候，切记pointer和其他的类型一样，要么传pointer to pointer 或着reference of the pointer!
 * */
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (key > root->val) root->right = deleteNode(root->right, key);
    	else if (key < root->val) root->left = deleteNode(root->left, key);
    	else if (root->left && root->right) {
			TreeNode* rightMin = root->right;
			while (rightMin->left) 
				rightMin = rightMin->left;

			root->val = rightMin->val;
			root->right = deleteNode(root->right, root->val);
		}
		else {
			TreeNode *tem =root->left? root->left:root->right;
			delete root;
			root = NULL;
			return tem;
		}
		return root;
    }
};
/* flowing cannot work *
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
    	deleteNodeHelp(root, key);
        return root;
    }

    void deleteNodeHelp(TreeNode* root, int key) {
        if (root == NULL) return;
        if (key > root->val) deleteNodeHelp(root->right, key);
    	else if (key < root->val) deleteNodeHelp(root->left, key);
    	else if (root->left && root->right) {
			TreeNode* rightMin = root->right;
			while (rightMin->left) 
				rightMin = rightMin->left;

			root->val = rightMin->val;
			deleteNodeHelp(root->right, root->val);
		}
		else {
			TreeNode *tem = root;
			if (root->left) 
				root = root->left;
			if (root->right)
				root = root->right;
			delete tem;
			tem = NULL;
		}
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 9ms solution without map becasue it's upp-bottom built, access the address of int works as using map*/
class Solution {
public:
    int rob(TreeNode* root) {
        int res = 0;
        int left = 0, right = 0;
        res = DFStravel(root, left, right);
        return res;
    }

    int DFStravel(TreeNode* root, int &left, int &right) {
    	if (root == NULL) return 0;
    	
    	int left_left = 0, left_right = 0, right_left = 0, right_right = 0;

    	left = DFStravel(root->left,left_left, left_right);
    	right = DFStravel(root->right, right_left, right_right);

    	return max(root->val + left_left + left_right + right_left + right_right, left + right);
    }
};

/* 12 ms solution using map to store calculated value at root*/
class Solution {
public:
    int rob(TreeNode* root) {
        int res = 0;
        unordered_map<TreeNode*, int> mymap;
        res = DFStravel(root, mymap);
        return res;
    }

    int DFStravel(TreeNode* root, unordered_map<TreeNode*, int> &mymap) {
    	if (root == NULL) return 0;
    	if (mymap.find(root) != mymap.end()) return mymap[root];

    	int rob = root->val;
    	int no_rob = DFStravel(root->left, mymap) + DFStravel(root->right, mymap);
    	if (root->left != NULL)
	    	rob += DFStravel(root->left->left, mymap) + DFStravel(root->left->right, mymap);
    	if (root->right != NULL)
    		rob += DFStravel(root->right->left, mymap) + DFStravel(root->right->right, mymap);
    	
    	mymap[root] = max(rob, no_rob);
    	return mymap[root];
    }
};
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
	bool findTarget(TreeNode* root, int k) {
		if (!root) return false;
		unordered_map<int, int> mydic;
		stack<TreeNode*> mystack;
		mystack.push(root);
		while (!mystack.empty()) {
			TreeNode* node = mystack.top();
			mystack.pop();
			
			if (mydic.find(k - node->val) != mydic.end())
				return true;
			mydic[node->val] ++;
			
			if (node->right) mystack.push(node->right);
			if (node->left)  mystack.push(node->left);
		}
		return false;
	}
};

/* the idea: we travel the tree while using a hashmap storeing
 * all tree value into a hashmap, each time we check if the value
 * k - node->val existed in hashmap, if so we are done
 */
/* alternative way: transfer BST to sorted array via inorder traversal
 */
/* alternative way: Binary Search, for each node do search k-node->val
 */

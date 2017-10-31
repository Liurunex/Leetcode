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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		vector<TreeNode*> res;
		unordered_map<string, int> nodedict;
		serialize(root, nodedict, res);
		return res;
	}

	string serialize(TreeNode* node, unordered_map<string, int>& nodedict, vector<TreeNode*>& res) {
		if (!node) return "_";
		string seristr;
		
		seristr += to_string(node->val) + serialize(node->left, nodedict, res) 
			+ serialize(node->right, nodedict, res);
		if (nodedict[seristr] == 1) res.push_back(node);
		nodedict[seristr] ++;
		return seristr;
	}
};

/* the idea: using the post-order/inorder traversal since we want to serilize the tree bottom up:
 * since it save time, if we serilized node from top down, we will calculate each node in serilization
 * multiple times. Besides that, using a hash map to record if frequncy of each serizlied string, we 
 * don't use hash set here, since the if a substree appears more than twice, hashset cannot detect it
 * has already push it into result vector, or we have to search the result vector to confirm, so that
 * hash map helps since it can record the frequency, that is only if we find the frequency is 1 we do 
 * the push operation on result vectors
 * /
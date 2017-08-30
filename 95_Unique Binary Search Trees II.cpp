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
	vector<TreeNode*> generateTrees(int n) {
		if (!n) return {};
		return helpgenerator(1, n);
	}

	vector<TreeNode*> helpgenerator(int lowerbound, int upperbound) {
		if (lowerbound > upperbound)
			return {{NULL}};

		vector<TreeNode*> its;
		for (int i = lowerbound; i <= upperbound; ++ i) {
			vector<TreeNode*> leftvector  = helpgenerator(lowerbound, i-1);
			vector<TreeNode*> rightvector =	helpgenerator(i+1, upperbound);
			for (int j = 0; j < leftvector.size(); ++ j) {
				for (int k = 0; k < rightvector.size(); ++ k) {
					TreeNode *node = new TreeNode(i);
					node->left  = leftvector.at(j);
					node->right = rightvector.at(k);
					its.push_back(node);
				}
			}
		}
		return its;
	}
};

/*
the idea is: for each parent node i, its left child subtree must be consisted by [lowerbound, i-1];
while its right child subtree must be consisted buy [i+1, upperbound], we keep recursively construct
the tree from up to down;
NOTICE: the termination of recursion is that lowerbound > upperbound, 'cause when lower == upper, it
actually has become the leaf cases where we cannot omit it; another trick is that in the termination case,
we must add the null pointer into it otherwise will not complete the tree construction
 */}

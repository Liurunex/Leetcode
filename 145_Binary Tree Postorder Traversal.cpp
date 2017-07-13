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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<pair<TreeNode *, int>> travelstack;
		TreeNode *curnode = root;
		while (1) {
			while (curnode) {
				travelstack.push(make_pair(curnode, 0));
				curnode = curnode->left;
			}

			if (!travelstack.empty()) {
				pair<TreeNode *, int> candiate = travelstack.top();
				if (candiate.first->right && !candiate.second) {
					curnode = candiate.first->right;
					travelstack.top().second = 1;
					continue;
				}

				travelstack.pop();
				res.push_back(candiate.first->val);
				continue;
			}
 			break;
		}  
		return res;
	}
};

/* revise from inorder iterate, modify the sack to pair type in order to record checked status of right child */
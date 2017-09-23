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
    vector<int> findMode(TreeNode* root) {
    	if (!root) return {};
    	vector<int> res;
    	stack<TreeNode*> mystack;
    	TreeNode* cur = root;
    	int maxlen = 0, curlen = 0, preval = root->val;
    	while(1) {
    		while (cur) {
    			mystack.push(cur);
    			cur = cur->left;
    		}
    		if (!mystack.empty()) {
    			TreeNode* node = mystack.top();
    			mystack.pop();
    			//cout << node->val << " " << curlen << " " << maxlen << endl;
    			if (node->val == preval) {
    				curlen ++;	
    			}
    			else curlen = 1;
  
				if (maxlen <= curlen) {
					if (maxlen < curlen) {
						maxlen = curlen;
						res.clear();
					}
					res.push_back(node->val);
				}
				preval = node->val;
    			
    			cur = node->right;
    			continue;
    		}
    		break;
    	}
    	return res;
    }
};

/* the idea: we applied the inorder traversal to the BST and we will get a non-decending
 * arrary, check the longest repeat string to return the result
 */

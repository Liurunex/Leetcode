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
    vector<int> rightSideView(TreeNode* root) {
    	if (!root) return {};
 		queue<TreeNode *> bfsqueue;
		vector<int> res;
		vector<TreeNode *> levelNodes;
		int levelCounter = 1;
		bfsqueue.push(root);
		
		while (!bfsqueue.empty()) {
			levelCounter = bfsqueue.size();

			while (levelCounter > 0) {	
				TreeNode* node = bfsqueue.front();
				bfsqueue.pop();
				levelNodes.push_back(node);

				if(node->left)
					bfsqueue.push(node->left);
				if(node->right)
					bfsqueue.push(node->right);

				levelCounter --;
			}
			res.push_back(levelNodes.back()->val);
			levelNodes.clear();
		}
    	return res;
    }
};
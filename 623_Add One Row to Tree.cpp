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
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode* newroot = new TreeNode(v);
			newroot->left = root;
			return newroot;
		}
		int cur = 1;
		int level_counter = 1;
		int next_level = 0;
		queue<TreeNode *> bfsqueue;
		bfsqueue.push(root);
		while (!bfsqueue.empty()) {
			if (cur == d-1) break;
			TreeNode* thenode = bfsqueue.front();
			bfsqueue.pop();
			level_counter --;

			if (thenode->left) {
				bfsqueue.push(thenode->left);
				next_level ++;
			}
			if (thenode->right) {
				bfsqueue.push(thenode->right);
				next_level ++;
			}

			if (!level_counter) {
				level_counter = next_level;
				next_level = 0;
				cur ++;
			}
		}

		while (!bfsqueue.empty()) {
			TreeNode *thenode = bfsqueue.front();
			bfsqueue.pop();

			TreeNode *newnode_l = new TreeNode(v);
			if (thenode->left)
				newnode_l->left = thenode->left;
			thenode->left = newnode_l;

			TreeNode *newnode_r = new TreeNode(v);
			if (thenode->right)
				newnode_r->right = thenode->right;
			thenode->right = newnode_r;
		}
		return root;
	}
};

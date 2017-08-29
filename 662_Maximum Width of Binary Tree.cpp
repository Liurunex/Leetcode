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
	int widthOfBinaryTree(TreeNode* root) {
		if (!root) return 0;
		int maxsize = INT_MIN;
		int level_start = 1, level_end = 1, pre_level = 1;
		queue<pair<TreeNode *, pair<int, int>>> myqueue;
		
		myqueue.push(make_pair(root, make_pair(1, 1)));
		
		while (!myqueue.empty()) {
			pair<TreeNode *, pair<int, int>> node = myqueue.front();
			myqueue.pop();

			if (node.second.first > pre_level) {
				//cout << "level: " << pre_level << " end = " << level_end << " start = " << level_start << endl;
				pre_level ++;
				maxsize     = max(maxsize, level_end-level_start+1);
				level_start = node.second.second;
				level_end   = level_start;
			}
			else level_end = node.second.second;
			
			if (node.first->left)
				myqueue.push(make_pair(node.first->left, make_pair(node.second.first+1, (node.second.second)*2-1)));
			if (node.first->right)
				myqueue.push(make_pair(node.first->right, make_pair(node.second.first+1, (node.second.second)*2)));
		}
		/* last level case */
		cout << "level: " << pre_level << " end = " << level_end << " start = " << level_start << endl;
		maxsize = max(maxsize, level_end-level_start+1);

		return maxsize;
	}
};

/* the problem here is you must remember to deal with the last level case otherwise you gonna lost it */
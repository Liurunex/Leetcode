/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		queue<pair<TreeLinkNode *, int>> myqueue;
		myqueue.push(make_pair(root, 0));
		pair<TreeLinkNode *, int> precessor = make_pair(root, 0);
		while (!myqueue.empty()) {
			pair<TreeLinkNode *, int> node = myqueue.front();
			myqueue.pop();
			if (node.first != root) {
				if (node.second == precessor.second) 	
					precessor.first->next = node.first;
				precessor = node;
			}
			if (node.first->left) myqueue.push(make_pair(node.first->left, node.second+1));
			if (node.first->right) myqueue.push(make_pair(node.first->right, node.second+1));
		}
	}
};
/* normal method of BFS using O(n) space, the following mehtod using O(1) */

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		
	}
};
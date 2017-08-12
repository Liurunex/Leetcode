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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		stack<TreeNode *> decend;
		for (int i = 0; i < nums.size(); ++ i) {
			TreeNode *node = new TreeNode(nums[i]);
			int findbigger = 0;
			if (decend.empty()) {
				decend.push(node);
				continue;
			}

			while (!decend.empty()){
				if (nums[i] > decend.top()->val) {
					node->left = decend.top();
					decend.pop();
					continue;
				}
				findbigger = 1;
				break;
			}
			
			if (findbigger)
				decend.top()->right = node;

			decend.push(node); 
		}
		while (decend.size() != 1)
			decend.pop();
		return decend.top();
	}
};

/*
use the stack to matian a decending sort, we keep update the right subtree root and left subtree root of the current root:
before push a new node, try to find the bigger node in stack, the bigger node's right subtree is new node, by going through 
the stack, we keep assigning the new node's left subtree, and pop out the less node in stack
 */

/*
The key idea is:
We scan numbers from left to right, build the tree one node by one step;
We use a stack to keep some (not all) tree nodes and ensure a decreasing order;
For each number, we keep pop the stack until empty or a bigger number; The bigger number 
(if exist, it will be still in stack) is current number's root, and the last popped number 
(if exist) is current number's right child (temporarily, this relationship may change in the future); 
Then we push current number into the stack.
 */
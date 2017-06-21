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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode *> inorderstack;
        TreeNode *curNode = root;
        TreeNode *res = NULL;
        int shouldreturn = 0;
        while (1) {
        	if (curNode) {
        		inorderstack.push(curNode);	
    			curNode = curNode->left;
    			continue;
        	}
        	if (!inorderstack.empty()) {
        		TreeNode *visit = inorderstack.top();
        		inorderstack.pop();

           		if (shouldreturn) return visit;
        		
        		if (p == visit) shouldreturn = 1;

        		curNode = visit->right;
        		continue;
        	}
        	break;
    	}
    	return res;
    }
};
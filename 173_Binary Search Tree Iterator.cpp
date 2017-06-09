/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
stack<TreeNode*> mystack;
public:
    BSTIterator(TreeNode *root) {
    	while (root != NULL) {
    		mystack.push(root);
    		root = root->left;
    	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mystack.empty();
    }

    /** @return the next smallest number */
    int next() {
    	if (mystack.empty()) return NULL;
        int res = mystack.top()->val;
        TreeNode* current = mystack.top();
        mystack.pop();
        if (current->right != NULL) {
        	current = current->right;
        	while (current != NULL) {
        		mystack.push(current);
        		current = current->left;
        	}
        }
    	return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

/* Recursive Solution: */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return HelpSymm(root->left, root->right);
    }

    bool HelpSymm(TreeNode* p1, TreeNode* p2) {
    	if (p1 == NULL && p2 == NULL)
    		return true;
    	if (p1 == NULL || p2 == NULL)
    	    return false;
    	if (p1->val == p2->val)
    		return HelpSymm(p1->left, p2->right) && HelpSymm(p1->right, p2->left);
    	return false;
    }
};

/* Iterator Solution: */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> visit;
        visit.push(root->left);
        visit.push(root->right);
        
        while (visit.size()) {
            TreeNode* p = visit.front();
            visit.pop();
            TreeNode* q = visit.front();
            visit.pop();
            
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            
            visit.push(p->left);
            visit.push(q->right);
            
            visit.push(p->right);
            visit.push(q->left);
        }
        return true;
    }
};

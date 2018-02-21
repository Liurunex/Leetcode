//先找depth
//recursive
class Solution {
public:
    int findDepth(TreeNode* root) {
        if (!root) return 0;
        return max(findDepth(root->left), findDepth(root->right)) + 1;    
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        int depth = findDepth(root);
        vector<vector<int>> res (depth, vector<int> {});
        
        helper(root, res, depth-1);
        return res;
    }
    
    void helper(TreeNode* root, vector<vector<int>>& res, int index) {
        if (!root) return;
        
        res[index].push_back(root->val);
        
        helper(root->left, res, index-1);
        helper(root->right, res, index-1);
    }
};
//iteartive
class Solution {
public:
    int findDepth(TreeNode* root) {
        if (!root) return 0;
        return max(findDepth(root->left), findDepth(root->right)) + 1;    
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        int depth = findDepth(root);
        vector<vector<int>> res (depth, vector<int> {});
        
        queue<TreeNode*> visit;
        visit.push(root);
        int index = depth-1;
        while (visit.size()) {
            int size = visit.size();
            for (int i = 0; i < size; ++ i) {
                TreeNode* node = visit.front();
                visit.pop();
                
                res[index].push_back(node->val);
                
                if (node->left)
                    visit.push(node->left);
                if (node->right)
                    visit.push(node->right);
            }
            index --;
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) 
            return vector<vector<int> > ();
		vector<vector<int>> output;
		stack<vector<int>> res;
		vector<int> level;
		queue<TreeNode*> myqueue;
		myqueue.push(root);
		int size = 1;

		while (!myqueue.empty()) {
			if (size == 0) {
				res.push(level);
				level.clear();
				size = myqueue.size();
			}
			TreeNode* node = myqueue.front();
			myqueue.pop();
			size --;
			level.push_back(node->val);
			if (node->left != NULL)
				myqueue.push(node->left);
			if (node->right != NULL)
				myqueue.push(node->right);
		}
        output.push_back(level);
		while (!res.empty()) {
			output.push_back(res.top());
			res.pop();
		}
		return output;
    }
};
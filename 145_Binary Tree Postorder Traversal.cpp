// two stacks 方法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> first;
        stack<TreeNode*> second;
        first.push(root);
        
        while (first.size()) {
            TreeNode* node = first.top();
            first.pop();
            second.push(node);
            if (node->left)
                first.push(node->left);
            if (node->right)
                first.push(node->right);
        }
        
        vector<int> res;
        while (second.size()) {
            res.push_back(second.top()->val);
            second.pop();
        }
        return res;
    }
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<pair<TreeNode *, int>> travelstack;
		TreeNode *curnode = root;
		while (1) {
			while (curnode) {
				travelstack.push(make_pair(curnode, 0));
				curnode = curnode->left;
			}

			if (!travelstack.empty()) {
				auto candiate = travelstack.top();
				if (candiate.first->right && !candiate.second) {
					curnode = candiate.first->right;
					travelstack.top().second = 1;
					continue;
				}

				travelstack.pop();
				res.push_back(candiate.first->val);
				continue;
			}
 			break;
		}  
		return res;
	}
};

/* revise from inorder iterate, modify the sack to pair type in order to record checked status of right child */
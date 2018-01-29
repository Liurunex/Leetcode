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
	int findClosestLeaf(TreeNode* root, int k) {
		int res = 0, val = 0;
		unordered_map<int, TreeNode*> ancestor;
		preTravel(root, k, val, res, ancestor, 0);
		return val;
	}

	void preTravel(TreeNode* root, int& k, int& val, int& res, 
		unordered_map<int, TreeNode*>& ancestor, int index) {
		
		if (!root) return;
		if (root->val == k) {
			auto path = lenToLeaf(root);
			res = path.first;
			val = path.second;
			for (int i = 0; i < index; ++ i) {
				auto tempath = lenToLeaf(ancestor[i]);
				if (res > index-i+tempath.first) {
					res = index-i+tempath.first;
					val = tempath.second;
				}
			}
			return;
		}
		ancestor[index] = root;
		preTravel(root->left, k, val, res, ancestor, index+1);
		preTravel(root->right, k, val, res, ancestor, index+1);
	}

	pair<int, int> lenToLeaf(TreeNode* root) {
		if (!root) return {INT_MAX, -1};
		if (!root->left && !root->right) {
			return {0, root->val};
		}
		auto leftpath  = lenToLeaf(root->left);
		auto rightpath = lenToLeaf(root->right);
		if (leftpath.first > rightpath.first)
			return {1+rightpath.first, rightpath.second};
		return {1+leftpath.first, leftpath.second};
	}
};

/* the idea: Preorder + Hashmap. 用preorder一直便利到k，然后计算以k为root向下到leaf的最小距离，接着对此前
 * 记录的k的parent全部计算其到Leaf的最小记录，这个距离修改后即为其他leaf以k的parent为中转站到k的距离，我们以此
 * 来更新距离，NOTICE:我们用hash-map来完成记录parent，方法是递归带一个index，记录parent的位置，所以如果左树没有
 * 找到k，虽然记录了k的parent，但在右树遍历到k时候会更新！
 *  */
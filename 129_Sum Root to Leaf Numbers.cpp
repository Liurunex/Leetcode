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
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		int sum = 0;
		stack<pair<TreeNode *, int>> dfsstack;
		vector<pair<int, int>> thepath;
		dfsstack.push(make_pair(root, 0));
		while(!dfsstack.empty()) {
			pair<TreeNode *, int> node = dfsstack.top();
			dfsstack.pop();

			while (!thepath.empty() && thepath.back().second != node.second-1)
				thepath.pop_back();

			thepath.push_back(make_pair(node.first->val, node.second));
			
			if (!node.first->right && !node.first->left) {
				caculate(thepath, sum);
				//cout << "sum: "<< sum << endl;
				thepath.pop_back();
			}
			

			if (node.first->right) dfsstack.push(make_pair(node.first->right, node.second+1));
			if (node.first->left)  dfsstack.push(make_pair(node.first->left, node.second+1));
		}
		return sum;
	}
	void caculate(vector<pair<int, int>> thepath, int &sum) {
		int digitloc = 1;
		//cout << thepath.size() << ": ";
		for (auto i = thepath.rbegin(); i != thepath.rend(); ++ i) {
			//cout << (*i).first << " ";
			
			if (digitloc == 1) sum += (*i).first;
			else sum += ((*i).first) * digitloc;
			
			digitloc *= 10;
		}
		//cout << endl;
	} 
};
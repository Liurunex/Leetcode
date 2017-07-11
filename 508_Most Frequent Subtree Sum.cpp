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
	vector<int> findFrequentTreeSum(TreeNode* root) {
		map<int, int> frequenDic;
		findsum(frequenDic, root);
		int maxFrenq = INT_MIN;
		for (auto i = frequenDic.begin(); i != frequenDic.end(); ++ i)
			maxFrenq = max(maxFrenq, i->second);
		vector<int> res;
		
		for (auto i = frequenDic.begin(); i != frequenDic.end(); ++ i) 
			if(i->second == maxFrenq) 
				res.push_back(i->first);

		return res;
	}

	int findsum(map<int, int> &frequenDic, TreeNode* node) {
		if (!node) return 0;
		int sum = node->val + findsum(frequenDic, node->left) + findsum(frequenDic, node->right);
		if (frequenDic.find(sum) == frequenDic.end()) 
			frequenDic[sum] = 1;
		else frequenDic[sum]++;

		return sum;
	}
};
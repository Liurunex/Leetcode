class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> comb;
		dfsbacktracking(res, comb, n, k, 1);
		return res;
	}

	void dfsbacktracking(vector<vector<int>> &res, vector<int> &comb, int &n, int k, int start) {
		if (comb.size() == k) {
			res.push_back(comb);
			return;
		}

		for (int i = start; i <= n; ++ i) {
			comb.push_back(i);
			dfsbacktracking(res, comb, n, k, i+1);
			comb.pop_back();
		}
	}
};
/* the idea: basic a backtracking dfs question
 */

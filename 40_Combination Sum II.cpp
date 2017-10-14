class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> com;
		dfshelper(candidates, target, res, 0, com);
		return res;
	}

	void dfshelper(vector<int>& candidates, int target, vector<vector<int>>& res, 
		int index, vector<int>& com) {
		if (!target) {
			res.push_back(com);
			return;
		}

		for (int i = index; i < candidates.size(); ++ i) {
			if (i > index && candidates[i] == candidates[i-1]) continue;
			if (target < candidates[i]) return;
			com.push_back(candidates[i]);
			dfshelper(candidates, target-candidates[i], res, i+1, com);
			com.pop_back();
		}
	}
};
/* the idea: almost same as combination I 39, the only difference is we should
 * pass i+1 as next recursive call start index;
 * the trick: notice that we should not consider the same number once we have
 * added it before, that the reason we should go check adjacent same numbers
 */

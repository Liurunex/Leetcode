class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> validcom;
		vector<vector<int>> res;
		backtracking(candidates, target, 0, validcom, res);
		return res;
	}

	void backtracking(vector<int>& candidates, int target, int index,
		vector<int>& validcom, vector<vector<int>>& res) {
		if (!target) {
			res.push_back(validcom);
			return;
		}
		for (int i = index; i < candidates.size(); ++ i) {
			if (target < candidates[i]) return;
			validcom.push_back(candidates[i]);
			backtracking(candidates, target-candidates[i], i, validcom, res);
			validcom.pop_back();
		}
	}
};

/* the idea: this is a typical backtracking question, using a vector to store
 * current numbers we have choosen to approch the target, the only trick is
 * we don't neet to check further cases if the target < candiate[i], meanwhile,
 * passing the begin index of candiates is necessary
 */

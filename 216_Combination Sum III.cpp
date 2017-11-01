class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> candidate;
		dfsBt(res, candidate, k, n);
		return res;
	}

	void dfsBt(vector<vector<int>>& res, vector<int>& candidate, int& k, int& n) {
		if (candidate.size() > k) return;
        if (candidate.size() == k && !n) {
			res.push_back(candidate);
			return;
		}
		for (int i = candidate.empty() ? 1:candidate.back()+1; i <= 9; ++ i) {
			if (n - i < 0) continue;
            candidate.push_back(i);
			n -= i;
			dfsBt(res, candidate, k, n);
			n += i;
			candidate.pop_back();
		}
	}
};

/* the idea: basically a DFS backtracking problem, what we should concerned is that
 * each number of 1..9 can use only once, therefore the starter of loop in backtracking
 * fucntion should be starter+1 in our case
 */

class Solution {
public:
	vector<vector<int>> getFactors(int n) {
		vector<vector<int>> res;
		vector<int> curres;
		backtrackhelper(n, 2, res, curres);
		return res;
	}

	void backtrackhelper(int target, int start, vector<vector<int>>& res, vector<int>& curres) {
		if (target == 1 && curres.size() > 1) {
			res.push_back(curres);
			return;
		}    
		for (int di = start; di <= target; ++ di) {
			if (!(target%di)) {
				curres.push_back(di);
				backtrackhelper(target/di, di, res, curres);
				curres.pop_back();
			}
		}
	}
};
/* the idea: basically a Backtracking  question, we just check from 2 to n if it was factor and build
 * the answer vector;
 * the trick: how to remove the duplicate cases. Here we deicede to traveal from given-start position to n
 * to check the factor, that is we give the ascending order of our output!
 */

/* a better idea: we just check from 2 to sqrt(n), easy to understand; but we cannot handle a single vector
 * for passing by reference, instead we attach a new vector for each cases, see the deatail below; in detail,
 * once we find a factor of target, we push both the factor and target/factor into our answer, before we push
 * the target/factor, we recursively call the backtracking function to find all possibile combinations for the 
 * target/factor
 */

class Solution {
public:
	vector<vector<int>> getFactors(int n) {
		vector<vector<int>> res;
		vector<int> curres;
		backtrackhelper(n, 2, res, curres);
		return res;
	}
	void backtrackhelper(int target, int start, vector<vector<int>>& res, vector<int> curres) {   
		for (int di = start; di <= sqrt(target); ++ di) {
			if (!(target%di)) {
				vector<int> newres (curres.beign(), curres.end());
				newres.push_back(di);
				backtrackhelper(target/di, di, res, newres);
				newres.push_back(target/di);

				res.push_back(newres);
			}
		}
	}
};

class Solution {
private:
	static bool comparator (vector<int>& i, vector<int>& j) { return i[0] < j[0]; }
public:

	int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() < 2) return pairs.size(); 
		sort(pairs.begin(), pairs.end(), comparator);
		int res = 1;
		vector<int> dp (pairs.size(), 1);
		for (int i = 1; i < pairs.size(); ++ i) {
			for (int j = 0; j < i; ++ j) {
				if (pairs[j][1] < pairs[i][0]) {
					dp[i] = max(dp[i], dp[j]+1);
					res = max(res, dp[i]);
				}
			}
		}
		return res;
	}	
};

/* the idea is mostly like the LIS DP, the difference is we must sort the pairs
 * at beginning based on the first element
 * the trick is: INITIAL THE RES VALUE AS 1
 */

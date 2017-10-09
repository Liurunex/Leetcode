class Solution {
public:
	bool canCross(vector<int>& stones) {
		if (!stones.size() || stones[0] != 0)
			return false;
		vector<unordered_set<int>> dp (stones.size(), unordered_set<int>());
		vector<int> maxJumps (stones.size(), 0);
		maxJumps[0] = 0;
		dp[0].insert(0);
		for (int i = 1; i < dp.size(); ++ i) {

			for (int j = 0; j < i; ++ j) {
				int dist = stones[i]-stones[j];
				while (maxJumps[j]+1 < dist) {
					j ++;
					dist = stones[i]-stones[j];
				}
				if (dp[j].count(dist) || dp[j].count(dist-1) || dp[j].count(dist+1)) {
					dp[i].insert(dist);
					maxJumps[i] = max(maxJumps[i], dist);
				}
			}
		}
		return dp[dp.size()-1].size() > 0;
	}
};
/* the idea: dp solution: dp[i] stores all possible units jumped from k to i where k < j, here
 * we use hash set to improve the performance; for each dp[i], we check from dp[k] to dp[i] where
 * the k is the first stone position that satisfy maximum jump units from k plus 1 unit >= distance between
 * i and k; based on this we should record the maximum junp unit at k position, that's why we build a 
 * maxJumps vectors and it is the key to speed up the performance. Once we have done above, we can then
 * iterated from stone k to stone i-1, check if the dist-1 or dist or dist+1 existed in corresponding
 * hashset, if it is true, we should simpy update the maxJumps and insert the dist into corresponding 
 * hashset
 * the trick is: SPEED UP by finding the first stone j which satisfy maxJumps[j]+1 >= distance between i and j
 */

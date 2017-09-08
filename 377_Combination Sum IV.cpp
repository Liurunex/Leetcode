class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
        if (!nums.size()) return 0;
		sort(nums.begin(), nums.end());
		vector<int> dp (target+1, 0);
        dp[0] = 1;
		for (int i = 1; i < target+1; ++ i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (i >= nums[j]) 
					dp[i] += dp[i-nums[j]];
				else break; 
			}
		}
		return dp[target];
	}
};

/*
 * the idea: dp, instead of digit dp, we use dp to record all possibilites
 * from 1 to target, the realtion is if (n > nums[i]) d[n] += dp[n-nums[i]];
 * 
 * Two tricks: we must assign dp[0] = 1, otherwise the dp cannot work, this is
 * our base solution, the reason is simple, since our relation dp[n] += dp[n-nums[i]], 
 * so that at beginning where dp[n] += dp[0] (n = 0 + num[i]), we cannot add this possibility;
 *
 * another trick: dp[n] += dp[n-nums[i]] cannot be changed to dp[n] += 1 + dp[n-nums[i]], otherwise
 * we will overcount results
 */

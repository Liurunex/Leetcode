class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> dp(num+1, 0);
		for (int i = 1; i<num+1; ++ i) {
			//if (i%2) dp[i] = dp[i-1]+1;
			//else dp[i] = dp[i>>1];
            dp[i] = dp[i>>1] + (i&1);
		}
		return dp;
	}
};

/* the idea: the dp subproblem is: if i is odd, dp[i] = dp[i-1]+1
 * else dp[i] = dp[i>>1], to be more concise, merge those cases
 * together; 
 */

/* anohter idea: from left to right side, take a look at solution_2 */

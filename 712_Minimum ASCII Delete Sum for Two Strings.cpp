class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, 0));

		for (int i = 1; i <= s1.size(); ++ i)
			dp[i][0] = (int)(s1[i-1]) + dp[i-1][0];

		for (int j = 1; j <= s2.size(); ++ j)
			dp[0][j] = (int)(s2[j-1]) + dp[0][j-1];
		
		for (int i = 1; i <= s1.size(); ++ i) {
			for (int j = 1; j <= s2.size(); ++ j) {
				if (s1[i-1] == s2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else 
					dp[i][j] = min(dp[i-1][j]+(int)(s1[i-1]), 
						dp[i][j-1]+(int)(s2[j-1]));
			}
		}
		return dp[s1.size()][s2.size()];
	}
};
/* the idea: typical a dp question, much similar to Edit_Distance and 583;
 * the only difference is we replace the opeartion number with ASCII code:
 * in detail: dp[i][j] means the minimal sum of ASCII code we removed to make
 * s1[0..i] = s2[0..j]: two cases: when s1[i] = s2[j] -> dp[i][j] = dp[i-1][j-1]
 * otherwise: we should consider the minial case of dp[i-1][j] + removed s1[i] and
 * dp[i][j-1] + removed s2[j];
 * the relate: consider the Longest SubSequnce of Strings
 * /

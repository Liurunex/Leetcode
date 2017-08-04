class Solution {
public:
	int minSteps(int n) {
		vector<int> dp (n+1, 0);
		for (int i = 2; i <= n; ++ i) {
			dp[i] = i;
			for (int j = 1; j < i/2; j ++) {
				if ((i-j)%j == 0)
					dp[i] = min (dp[j] + 1 + (i-j)/j, dp[i]);
			} 
		}
		return dp[n];
	}
};
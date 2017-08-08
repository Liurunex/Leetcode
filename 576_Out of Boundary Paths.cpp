class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		vector<vector<vector<size_t>>> dp(N+1, vector<vector<size_t>> (m, vector<size_t>(n, 0)));
		size_t modnum = 1000000007;
		for (int k = 1; k <= N; ++ k) {
			for (int i = 0; i < m; ++ i) {
				for (int j = 0; j < n; ++ j) {
					dp[k][i][j] += i == 0   ? 1:dp[k-1][i-1][j];
					dp[k][i][j] += i == m-1 ? 1:dp[k-1][i+1][j];
					dp[k][i][j] += j == 0   ? 1:dp[k-1][i][j-1];
					dp[k][i][j] += j == n-1 ? 1:dp[k-1][i][j+1];
					dp[k][i][j] %= modnum;
				}
			}
		}

		return dp[N][i][j];
	}
};
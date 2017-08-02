class Solution {
public:
    int maxA(int N) {
		vector<int> dp (N+1, 0);
		for (int i = 1; i < N+1; i ++) {
			dp[i] = i;
			for (int j = 3; j < i; j ++) {
				dp[i] = max(dp[i], dp[i-j]*(j-1));
			}
		}
		return dp[N];
	}
};

/* actally there is a O(n) mehotd, see the induction proof here https://discuss.leetcode.com/topic/97721/mathematical-proof-of-the-o-n-solution*/
public int maxA(int N) {
	if (N <= 6)  return N;
	int[] dp = new int[N + 1];
	for (int i = 1; i <= 6; i++)
		dp[i] = i;
	for (int i = 7; i <= N; i++)
		dp[i] = Math.max(dp[i - 4] * 3, dp[i - 5] * 4);
		// dp[i] = Math.max(dp[i - 4] * 3, Math.max(dp[i - 5] * 4, dp[i - 6] * 5));
	return dp[N];
}
class Solution {
public:
    int integerBreak(int n) {
    	if (n < 3) return 1;
        vector<int> dp (n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i < n+1; ++ i) {
        	for (int j = 1; j < i; ++ j)
        		dp[i] = max(dp[i], max(dp[j], j) * max(dp[i-j], i - j));
        }
        return dp[n];
    }
};

/* NOTICE: do the dp need to be aware of not you should both consider the cases :
	dp[i] * dp[i-j], dp[i] * (i-j), j * dp[i-j], j * (i - j)
*/
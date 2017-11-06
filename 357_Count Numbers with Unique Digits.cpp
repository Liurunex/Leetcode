class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
		if (n == 1) return 10;
		if (n == 2) return 91;

		vector<int> dp (n+1, 0);
		dp[1] = 10;
		dp[2] = 81;
		int res = dp[1] + dp[2];
		for (int i = 3; i <= n; ++ i) {
			if (i >= 11) return res;
			dp[i] = dp[i-1] * (9-i+2);
			res += dp[i];
		}
		return res;
	}
};

/* the idea: math combination question:
 * for n-digit number, the unique number counter: 9 * 9 * 8 * 7...
 * NOTICE the limit is 11, were there is no more unique number further
 * /
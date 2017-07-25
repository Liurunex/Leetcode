class Solution {
public:
	int numSquares(int n) {
		if (n <= 0) return 0;
		vector<int> dp (n+1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; ++ i) 
			for (int j = 1; j*j <= i; ++ j) 
				dp[i] = min(dp[i], dp[i - j*j] + 1);
			
		return dp[n];
	}
};

/* a trick way: set the vector to static, so that all used case 
	will not be calculate again in other test cases
*/

class Solution {
public:
	int numSquares(int n) {
		if (n <= 0) return 0;
		static vector<int> dp (1,0);
		while (dp.size() < n+1) {
			int tem = INT_MAX;
			for (int i = 1; i*i <= dp.size(); ++ i) 
				tem = min(tem, dp[dp.size() - i*i] + 1);
			dp.push_back(tem);
		}	
		return dp[n];
	}
};

/* consider the Math_thoery solution which is the most fast */
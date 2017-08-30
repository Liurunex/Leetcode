class Solution {
public:
	int numTrees(int n) {
		vector<int> dp (n+1, 0);
		dp[0] = 1;
		for (int i = 1; i < n+1; i ++) {
			for (int j = 0; j < i; j ++)
				dp[i] += dp[j]*dp[i-j-1];
		}	
		return dp[n];
	}
};

/*
the idea is: (bottom to up construction)
select the root from 1 to n;
for the i case (i is the maxmium element inside), 
its left possible child is
from null to i-1, while its corresponding right
possible child is from i-1 to 0;
thus totall possibilities is dp(i) = -||(dp(j)*dp(i-j-1));
 */
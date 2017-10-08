class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp (amount+1, 0);

		dp[0] = 1;
		for (int j = 0; j < coins.size(); ++ j) {
			for (int i = coins[j]; i <= amount; ++ i) {
				dp[i] += dp[i-coins[j]];
			}
		}
		return dp[amount];
	}
};
/* the idea: normally it's a knackpack dp question: we set dp[i] = the number 
 * of combinations; go from first coin to last coin, since we can use it infinite
 * times, we first use it to build all possible values it could form up to the 
 * target one; repeating this process and we are done
 */

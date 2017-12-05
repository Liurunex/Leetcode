class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> dp (temperatures.size(), -1);
		for (int i = temperatures.size()-2; i >= 0; -- i) {
			if (temperatures[i] < temperatures[i+1])
				dp[i] = i+1;
			else {
				int index = i+1;
				while (index < temperatures.size() && dp[index] != -1
					&& temperatures[dp[index]] <= temperatures[i]) {
					index = dp[index];
				}
				if (index < temperatures.size() && dp[index] != -1)
					dp[i] = dp[index];
			}
		}
		vector<int> res (temperatures.size(), 0);
		for (int i = 0; i < temperatures.size(); ++ i) {
			//cout << dp[i] << " ";
			if (dp[i] != -1)
				res[i] = dp[i]-i;
		}
		return res;
	}
};

/* the idea: memorized table: here we used a vector to store the index of 
 * next larger element for each number, notice we do this from back to begin,
 * the reason is simple, the search ranger for back element is increasing.
 * What we do is, at each position i, we check if num[i] < num[i+1], if so
 * we have find the next greater element towards i, otherwise we should do
 * a jump search: that is check num[i] < num[dp[i+1]] until we reach the end
 * or find the one!
 * Finally we just process the dp table to get the distance res;
 */

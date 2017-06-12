class Solution {
public:
	int numDecodings(string s) {
		if (!s.size()) return 0;
		if (s.size() == 1) return (s[0] >= '1' && s[0] <= '9');
		if (s[0] > '9' || s[0] <= '0') return 0;

		vector<int> dp (s.size()+1, 1);
		for (int i = 2; i < s.size()+1; ++ i) {
			if (s[i-1] > '9' || s[i-1] < '0' || !dp[i-1]) return 0;

			int sum = (int)(s[i-1]-'0')+10*(int)(s[i-2]-'0');
			if (s[i-1] == '0') {
				if (sum >= 10 && sum <= 26) dp[i] = dp[i-2];
				else dp[i] = 0;
			}
			else dp[i] = (sum >= 10 && sum <= 26) ? dp[i-2]+dp[i-1] : dp[i-1];
		}
		return dp[s.size()];
	}
};

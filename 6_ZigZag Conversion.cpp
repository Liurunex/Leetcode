class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1 || s == "") return s;
		vector<string> dp(numRows, "");
		int dirction = 1;
		int j = 0;
		for (int i = 0; i < (int)s.length(); i ++) {
			if (dirction) {
				if (j >= numRows) {
					j -= 2;
					dp[j] += s[i];
					j --;
					dirction = 0;
				}
				else {
					dp[j] += s[i];
					j ++;
				}
			}
			else {
				if (j < 0) {
					j += 2;
					dp[j] += s[i];
					j ++;
					dirction = 1;
				}
				else {
					dp[j] += s[i];
					j --;
				}
			}
		}
		string res;
		for (int i = 0; i < numRows; ++ i)
			res += dp[i];
		return res;
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<int>> dp (s.size()+1, vector<int>(p.size()+1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < s.size()+1; ++ i) {
			for (int j = 1; j < p.size()+1; ++ j) {
				if (p[j-1] == '*') {
					// '*' go match empty sequnce
					dp[i][j] = dp[i][j-1];
					// '*' go match n-size sequnce where n > 0
					if (!dp[i][j])
						dp[i][j] = i > 0 && dp[i-1][j];
				}
				else if (p[j-1] == '?') {
					dp[i][j] = i > 0 && dp[i-1][j-1];
				}
				else {
					dp[i][j] = i > 0 && dp[i-1][j-1] && s[i-1] == p[j-1];
				}
			}
		}
		return dp[s.size()][p.size()];
	}
};
/* the idea: DP. 和regular expression match 一个套路，唯一区别是p[j-1] = '*'时候，可以替代
 * 任意长度的string，所以只考虑2 cases：*替换empty sequence，和替换n-size sequence, 同样后者
 * 用了recursive的想法，如果*替换了s[i-1],那么接下来考虑s[i-2]，其实在dp[i-1][j]已经考虑了！*/
class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<int>> dp (s.size()+1, vector<int>(p.size()+1, 0));
		dp[0][0] = 1;
		for (int i = 0; i <= s.size(); ++ i) {
			for (int j = 1; j <= p.size(); ++ j) {
				if (p[j-1] == '*' && j > 1) {
					//match 0 p[j-2] in s
					dp[i][j] = dp[i][j-2];
					//match 1 p[j-2] in s
					if (!dp[i][j])
						dp[i][j] = dp[i][j-1];
					//match n p[j-2] in s
					if (!dp[i][j])
						dp[i][j] = i > 0 && (p[j-2] == '.' || p[j-2] == s[i-1]) && dp[i-1][j];
				}
				else if (p[j-1] == '.')
						dp[i][j] = i > 0 && dp[i-1][j-1];
				else if (p[j-1] != '.' && p[j-1] != '*')
					dp[i][j] = i > 0 && dp[i-1][j-1] && s[i-1] == p[j-1];
			}
		}
		return dp[s.size()][p.size()];
	}
};
/* the idea: DP. string匹配问题用dp，dp[i][j]是s[0..i-1]匹配 p[0..j-1], 3种cases：
 * p[j-1] == letter：前面dp[i-1][j-1]匹配 + 当前字符匹配
 * 			dp[i][j] = dp[i-1][j-1] && p[j-1] = s[i-1]
 * p[j-1] == '.'：只需看前面dp[i-1][j-1]是否匹配
 * 			dp[i][j] = dp[i-1][j-1]
 * p[j-1] == '*': 匹配多少p[j-2]？
 * 			匹配0个p[j-2] -> dp[i][j] = dp[i][j-2]
 * 			匹配1个p[j-2] -> dp[i][j] = dp[i][j-1]
 * 			匹配n个p[j-2] -> dp[i][j] = s[i-1] == p[j-2] && dp[i-1][j]
 *    	最后一个tricky: 如果要匹配n个(n>0)，现比较tail是否等，然后用p[0..j-1]去match s[0..i-2],
 *    	这是一个recursive的思想：依然看以上三个case,（case 2 and case 3 can be mergered）
 * NOTICE the initial case dp[0][0] = 1;
 * */
 
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp (s.size()+1, vector<bool> (p.size()+1, false));
        dp[0][0] = 1;

        for (int i = 0; i <= s.size(); ++ i) {
            for (int j = 1; j <= p.size(); ++ j) {
                switch (p[j-1]) {
                    case '*':
                        if (j < 2) break; 
                        dp[i][j] = dp[i][j-2]; //match 0 p[j-2]
                        if (!dp[i][j])
                            dp[i][j] = dp[i][j-1]; //match 1 p[j-2]
                        if (!dp[i][j])
                            dp[i][j] = i>0 && (p[j-2] == '.' || s[i-1] == p[j-2]) && dp[i-1][j];
                        break;
                    case '.': 
                        dp[i][j] = i>0 && dp[i-1][j-1];
                        break;
                    default:
                        dp[i][j] = i>0 && s[i-1] == p[j-1] && dp[i-1][j-1];
                }
            }
        }
        return dp.back().back();
    }
};
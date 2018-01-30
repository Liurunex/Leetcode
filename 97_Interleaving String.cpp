class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<bool>> dp (s1.size()+1, vector<bool>(s2.size()+1, false));
        // initilize 
        dp[0][0] = true;     
        for (int i = 1; i < s1.size()+1; ++ i)
            dp[i][0] = dp[i-1][0] && s3[i-1] == s1[i-1];
        for (int j = 1; j < s2.size()+1; ++ j) 
            dp[0][j] = dp[0][j-1] && s3[j-1] == s2[j-1];
        // dp iteration
        for (int i = 1; i < s1.length()+1; i ++) {
            for (int j = 1; j < s2.length()+1; j++) {
                if (s3[i+j-1] == s1[i-1] && s3[i+j-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else if (s3[i+j-1] == s1[i-1])
                    dp[i][j] = dp[i-1][j];
                else if (s3[i+j-1] == s2[j-1])
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[s1.length()][s2.length()];
    }
};

/* the idea:
*/
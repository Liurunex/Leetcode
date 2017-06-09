class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0, j = 0, start = 0, end = 0, len = s.size();
        bool dp[len][len];
        memset(dp, false, len*len*sizeof(bool));

        for (i = 0; i < len; i++)
            dp[i][i] = true;

        for (j = 0; j < len; j++) {
            for (i = 0; i < j; i++) {
                dp[i][j] = (s[i] == s[j]) && (i+1 == j || dp[i+1][j-1]);
                if (dp[i][j] && j-i+1 > end-start+1) {
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end-start+1);
    }   
};
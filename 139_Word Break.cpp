class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.length()+1];
        int i, j= 0;
        dp[0] = true;

        for (i = 1; i<s.length()+1; i++) {
            dp[i] = false;
            for (j = i-1; j>=0; j--) { 
                if (dp[j]) {
                    if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
     	if (s1.length() + s2.length() != s3.length())
     		return false;
        int i, j = 0;
        bool dp[s1.length()+1][s2.length()+1];

        for (i = 0; i < s1.length()+1; i ++) {
        	for (j = 0; j < s2.length()+1; j++) {
        		dp[i][j] = false;
        		
        		if (i == 0 && j == 0)
        			dp[i][j] = true;

        		if (i == 0 && j > 0) {
        			if (s2[j-1] == s3[i+j-1])
        				dp[i][j] = dp[i][j-1];
        		}

    			if (i > 0 && j == 0) {
    				if (s1[i-1] == s3[i+j-1])
        				dp[i][j] = dp[i-1][j];
    			}
    		
				if (i > 0 && j > 0) {
					if (s3[i+j-1] == s1[i-1] && s3[i+j-1] == s2[j-1])
					    dp[i][j] = dp[i-1][j] || dp[i][j-1];
					else {
					    if (s3[i+j-1] == s1[i-1])
						    dp[i][j] = dp[i-1][j];
				    	if (s3[i+j-1] == s2[j-1])
						    dp[i][j] = dp[i][j-1];
					}
				}
        	}
        }
    	return dp[s1.length()][s2.length()];
    }
};
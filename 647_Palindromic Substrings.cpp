class Solution {
public:
    int countSubstrings(string s) {
        int totalcount = s.size();
        vector<vector<int>> dp (s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++ i)
        	dp[i][i] = 1;
        for (int i = s.size()-1; i >= 0; -- i) {
        	for (int j = i+1; j < s.size(); ++ j) {
        		dp[i][j] = s[i] == s[j] && (i+1 == j || dp[i+1][j-1]);
    			totalcount += dp[i][j];
        	}
        }
        return totalcount;
    }
};

/*
O(n^2): the dp[i][j] means if string i..j is palindromic, be careful that the nest loop
should go from n->0 in outter loop
 */

/*
the post indicates another solution:
https://discuss.leetcode.com/topic/96822/python-straightforward-with-explanation-bonus-o-n-solution/3
 */
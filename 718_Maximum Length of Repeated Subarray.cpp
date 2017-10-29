class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (!A.size() || !B.size()) return 0;
        vector<vector<int>> dp (2, vector<int> (B.size()+1, 0));
        int res = 0;
        for (int i = 1; i < A.size()+1; ++ i) {
        	int k = i&1;
        	for (int j = 1; j < B.size()+1; ++ j) {
        		if (A[i-1] == B[j-1]) {
        			dp[k][j] = dp[k^1][j-1]+1;
        			res = max(res, dp[k][j]);
        		}
        		else dp[k][j] = 0;
        	}
        }
        return res;
    }
};
/* the idea: simple dp with longest same substring, the trick is how
 * to avoid memory limit, original dp using O(n^2), here we used so-called
 * rolling array, that is only to record the adjacent states of the dp table
 * in this case, we use bit maluputation k, notice how we manupluate it
 */

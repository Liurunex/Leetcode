class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
		for (string target : strs) {	
			int onecount  = 0;
			int zerocount = 0;
			for (char it : target) {
				if (it == '1') onecount ++;
				else zerocount ++;
			}

			for (int i = m; i >= zerocount; -- i) {
				for (int j = n; j >= onecount; -- j) {
					dp[i][j] = max(dp[i-zerocount][j-onecount] + 1, dp[i][j]);
				}
			}
		}
		return dp[m][n];
	}
};

/*
dp[i][j] is the max number of strings that can be formed with i 0's and j 1's from the first strings up to the current one;
Q: have to go from bottom right to top left
A: If a cell in the dp is updated as s is selected, we should be increase dp[i][j] by 1 from the previous iteration 
where we were not considering the new string s. If we go from top left to bottom right, we would uss results from iteration,
causing overcounting
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>>dp (obstacleGrid.size()+1, 
			vector<int>(obstacleGrid[0].size()+1, 0));
		dp[0][1] = 1;
		for (int i = 1; i < dp.size(); ++ i) {
			for (int j = 1; j < dp[0].size(); ++ j) {
				if (!obstacleGrid[i-1][j-1])
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[dp.size()-1][dp[0].size()-1];
	}
};
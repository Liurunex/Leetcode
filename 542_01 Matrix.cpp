class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if(!matrix.size()) return matrix;
		vector<vector<int>> dp (matrix.size(), vector<int> (matrix[0].size(), INT_MAX-1));
		for (int i = 0; i < matrix.size(); ++ i) {
			for (int j = 0; j < matrix[0].size(); ++ j) {
				if (!matrix[i][j]) dp[i][j] = 0;
				else {
					if (i-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1); //cannot be dp[i-1][j]+1, since it might update the value to INT_MAX then cause overflow )
					if (j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
				}
			}
		}
		for (int i = matrix.size()-1; i >= 0; -- i) {
			for (int j = matrix[0].size()-1; j >= 0; -- j) { 
				if (dp[i][j] && dp[i][j] != 1) {
					if (i+1 < matrix.size()) dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
					if (j+1 < matrix[0].size()) dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
				}
			}
		}
		return dp;

	}
};

/* this is a two-round solution, there might be a one-round solution */
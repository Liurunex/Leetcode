class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (!matrix.size()) return 0;
		vector<vector<int>> dp (matrix.size()+1, vector<int> (matrix[0].size()+1, 0));
		int maxlen = 0;
		for (int i = 1; i < matrix.size()+1; ++ i) {
			for (int j = 1; j < matrix[0].size()+1; ++ j) {
				if (matrix[i-1][j-1] == '1') {
					dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
					maxlen   = max(maxlen, dp[i][j]);
				}
			}
		}
		return maxlen*maxlen;
	}
};

/* the idea: dp[i][j] means the maximum length of square where it's the lower right node
of the squre, then we can easily get the realtion fucntion:
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1, the reasone we use min fucntion
here is that we can only pick the one exsiting minner square otherwise the the new square 
cannot be formed completely, it might miss some noodes; 

Notice: for easliy implememt, you should consider add a fake wall with 0 to wrap the matrix,
otherwise you have to write 2 additional loops to set the first coloum and row values in dp 
*/
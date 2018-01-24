class NumMatrix {
private:
	vector<vector<int>> sums;
public:
	NumMatrix(vector<vector<int>> matrix) {
        if (!matrix.size() || !matrix[0].size()) return;
		sums.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        sums[1][1] = matrix[0][0];
		for (int i = 2; i < sums.size(); ++ i)
			sums[i][1] = sums[i-1][1] + matrix[i-1][0];
		for (int j = 2; j < sums[0].size(); ++ j)
			sums[1][j] = sums[1][j-1] + matrix[0][j-1];
		for (int i = 2; i < sums.size(); ++ i) {
			for (int j = 2; j < sums[0].size(); ++ j) {
				sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i-1][j-1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sums[row2+1][col2+1] + sums[row1][col1] - sums[row1][col2+1] - sums[row2+1][col1];
	}
};
/* the idea: Prefix-Sum. The idea is same as Range Sum Query immutable. Here we use a matrix sums to store
 * the sum from matrix[0][0] to matrix[i][j]. NOTICE we set the new matrix sums as size+1 at both row and col,
 * this is to deal with the problem of calculating the sum of range: for sum from [row1][col1] to [row2][col2],
 * what we should consider is remove sums[row1-1][col-1] and other two part from sums[row2][col2]
 * */
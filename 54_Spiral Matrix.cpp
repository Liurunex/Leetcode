class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
 		if (matrix.empty()) return {};
		int direction = 0, allnodes = matrix.size()*matrix[0].size();
		int row_index = 0, col_index = 0, count = 0;
		int south_limit = matrix.size()-1, east_limit = matrix[0].size()-1;
		int north_limit = 1, west_limit = 0;
		vector<int> res;
		while (count < allnodes) {
			switch (direction) {
				case 0: {
					while (east_limit >= col_index) {
						res.push_back(matrix[row_index][col_index]);
						//cout << matrix[row_index][col_index] << " ";
						col_index ++;
						count ++;
					}
					col_index = east_limit;
					row_index ++;
					east_limit --;
					direction = (direction+1)%4;
					break;
				}
				case 1: {
					while (south_limit >= row_index) {
						res.push_back(matrix[row_index][col_index]);
						//cout << matrix[row_index][col_index] << " ";
						row_index ++;
						count ++;
					}
					row_index = south_limit;
					col_index --;
					south_limit --;
					direction = (direction+1)%4;
					break;
				}
				case 2: {
					while (col_index >= west_limit) {
						res.push_back(matrix[row_index][col_index]);
						//cout << matrix[row_index][col_index] << " ";
						col_index --;
						count ++;
					}
					col_index = west_limit;
					row_index --;
					west_limit ++;
					direction = (direction+1)%4;
					break;
				}
				default: {
					while (row_index >= north_limit) {
						res.push_back(matrix[row_index][col_index]);
						//cout << matrix[row_index][col_index] << " ";
						row_index --;
						count ++;
					}
					row_index = north_limit;
					col_index ++;
					north_limit ++;
					direction = (direction+1)%4;
				}
			}
		}
		return res;
	}
};

class Solution {
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
		if (grid.size() == 0) return 0;
		int res = 0;
		vector<vector<int>> table(grid.size(), vector<int> (grid[0].size(), 0));
		if (grid[0].size() != 1) {
			for (int i = 0; i < grid.size(); ++ i) {
				int rcount = 0, rstart = 0, rend = 0, isW = 0;
				for (int j = 0; j < grid[0].size(); ++ j) {
					isW = 0;
					if (grid[i][j] == 'E') {
						rcount ++;
						rend = j;
					}
					else if (grid[i][j] == '0') rend = j;
					else if (grid[i][j] == 'W') {
						for (int k = rstart; k <= rend; ++ k) {
							if (grid[i][k] == '0') {
								table[i][k] = rcount;
								res = max(res, rcount);
							}
						}
						rcount = 0;
						rstart = rend = j+1;
						isW = 1;
					}
					if (j == grid[0].size()-1 && !isW) {
						for (int k = rstart; k <= rend; ++ k) {
							if (grid[i][k] == '0') {
								table[i][k] = rcount;
								res = max(res, rcount);
							}
						}
					}
				}
			}
		}

		if (grid.size() == 1) return res;
		for (int j = 0; j < grid[0].size(); ++ j) {
			int count = 0, start = 0, end = 0, isW = 0;
			for (int i = 0; i < grid.size(); ++ i){
				isW = 0;
				if (grid[i][j] == 'E') {
					count ++;
					end = i;
				}
				else if (grid[i][j] == '0') end = i;
				else if (grid[i][j] == 'W') {
					for (int k = start; k <= end; ++ k) {
						if (grid[k][j] == '0') {
							table[k][j] += count;
							res = max(res, table[k][j]);
						}
					}
					count = 0;
					start = end = i+1;
					isW = 1;
				}
				if (i == grid.size()-1 && !isW) {
					for (int k = start; k <= end; ++ k) {
						if (grid[k][j] == '0') {
							table[k][j] += count;
							res = max(res, table[k][j]);
						}
					}
				}
			}
		}

		return res;
	}
};

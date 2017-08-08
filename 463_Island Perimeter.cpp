class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int res = 0;
		for (int i = 0; i < grid.size(); ++ i) {
			for (int j = 0; j < grid[0].size(); ++ j) {
				if (grid[i][j] == 1) {
					res += 4;
					res -= i+1 < grid.size() && grid[i+1][j] ? 2:0;
					res -= j+1 < grid[0].size() && grid[i][j+1] ? 2:0;
				}
			}
		}
		return res;
	}
};
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int res = INT_MIN;
		vector<pair<int, int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
		queue<pair<int, int>> candiates;
		vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
		for (int i = 0; i < grid.size(); ++ i) {
			for (int j = 0; j < grid[0].size(); ++ j) {
				if (grid[i][j]) {
					candiates.push({i, j});
					int counter = 0;
					while (!candiates.empty()) {
						pair<int, int> land = candiates.front();
						candiates.pop();
						counter ++;
						grid[land.first][land.second] = 0;
						for (auto move:direction) {
							int x = move.first + land.first;
							int y = move.second + land.second;
							if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && 
								grid[x][y] && !visited[x][y]) {
								visited[x][y] = 1;
								candiates.push({x, y});
							}
						}
					}
					//cout << counter << endl;
					res = max(res, counter);
				}
			}
		}
		return res == INT_MIN ? 0:res;
	}
};
/* the idea: same as the number of island question */

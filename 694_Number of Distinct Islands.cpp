class Solution {
public:
	int numDistinctIslands(vector<vector<int>>& grid) {
		unordered_set<string> numIsland;
		for (int i = 0; i < grid.size(); ++ i) {
			for (int j = 0; j < grid[0].size(); ++ j) {
				if (grid[i][j]) {
					string shape = "S";
					dfs_helper(grid, i, j, shape);
					numIsland.insert(shape);
				}
			}
		}
		return numIsland.size();
	}

	void dfs_helper(vector<vector<int>>& grid, int x, int y, string& s) {
		grid[x][y] = 0;

		if (x+1 < grid.size() && grid[x+1][y]) {
			s += 'D';
			dfs_helper(grid, x+1, y, s);
		}
		s += '#';
		if (y-1 >= 0 && grid[x][y-1]) {
			s += 'L';
			dfs_helper(grid, x, y-1, s);
		}
		s += '#';
		if (x-1 >= 0 && grid[x-1][y]) {
			s += 'U';
			dfs_helper(grid, x-1, y, s);
		}
		s += '#';
		if (y+1 < grid[0].size() && grid[x][y+1]) {
			s += 'R';
			dfs_helper(grid, x, y+1, s);
		}
		s += '#';
	}
};
/* the idea: same as DFS
 * the trick: we want to record the decision we make on each
 * step of DFS, but notice to add a mark to record if we 
 * don't have a choice, that is add # to determine one way of
 * dfs has reached the end, otherwise we will met same reuslts
 * for different shape, eg 110 011 000 111 010
 */

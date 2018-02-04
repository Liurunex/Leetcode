class Solution {
public:
	int containVirus(vector<vector<int>>& grid) {
		int res = 0;
		while (1) {
			int adds = buildWall(grid);
			if (!adds) return res;
			res += adds;
		}
		return res;
	}

	int buildWall(vector<vector<int>>& grid) {
		int maxAreas = 0, ci = -1, cj = -1, res = 0;
		vector<pair<int,int>> virusStart;
		vector<vector<int>> visited (grid.size(), vector<int>(grid[0].size(), 0));
		unordered_set<double> countedAres;
		for (int i = 0; i < grid.size(); ++ i) {
			for (int j = 0; j < grid[0].size(); ++ j) {
				if (grid[i][j] == 1 && !visited[i][j]) {
					countedAres.clear();
					virusStart.push_back({i, j});
					int walls = 0;
					int area = dfstravel(i, j, grid, visited, walls, countedAres);
					if (area > maxAreas) {
						maxAreas = area;
						res = walls;
						ci = i;
						cj = j;
					}
				}
			}
		}
		// build the walls
		clearArea(ci, cj, grid);
		// spread the virus
		visited = vector<vector<int>> (grid.size(), vector<int>(grid[0].size(), 0));
		for (auto pairs:virusStart) {
			if (pairs.first == ci && pairs.second == cj)
				continue;
			spreadArea(pairs.first, pairs.second, grid, visited);
		}
		return res;
	}

	double toCom(int i, int j) {
		double res = j+1;
		while (res > 1)
			res /= 10;
		return res+i+1;
	}

	int dfstravel(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int& walls, unordered_set<double>& countedAres) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
			return 0;
		if (!grid[i][j]) {
			walls ++;
			double com = toCom(i, j);
			if (countedAres.count(com)) {
				return 0;
			}
            countedAres.insert(com);
			return 1;
		}
		if (grid[i][j] != 1 || visited[i][j]) return 0;
		visited[i][j] = 1;
		int area = 0;
		area += dfstravel(i+1, j, grid, visited, walls, countedAres);
		area += dfstravel(i-1, j, grid, visited, walls, countedAres);
		area += dfstravel(i, j+1, grid, visited, walls, countedAres);
		area += dfstravel(i, j-1, grid, visited, walls, countedAres);
		return area;
	}

	void clearArea(int i, int j, vector<vector<int>>& grid) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
			return;

		grid[i][j] = -1;
		clearArea(i+1, j, grid);
		clearArea(i-1, j, grid);
		clearArea(i, j+1, grid);
		clearArea(i, j-1, grid);
	}

	void spreadArea(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j])
			return;

		visited[i][j] = 1;
		if (!grid[i][j])
			grid[i][j] = 1;
		else if (grid[i][j] == 1) {
		    spreadArea(i+1, j, grid, visited);
		    spreadArea(i-1, j, grid, visited);
		    spreadArea(i, j+1, grid, visited);
		    spreadArea(i, j-1, grid, visited);
        }
	}
};

/* the idea : DFS + Simulation. 纯dfs，先找出所有感染区，计算next感染cell number，和对应的要围起来的wall，挑
 * next感染区最多的，然后clear掉，接着simulate其他区域感染，循环到没有新的next感染区. NOTICE: next感染区和wall不是
* 一个东西，不能重复计算多个已感染区去感染一个地方，虽然其需求的wall要重叠计算，using hash-set here, since hash-set
* cannot support pair, we need to convert i and j into a single double number, NOTICE i and j should change to start at 1
* */
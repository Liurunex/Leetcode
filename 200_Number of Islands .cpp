class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (!grid.size()) return 0;
		int res = 0;
		for (int i = 0; i < grid.size(); ++ i) {
			for (int j = 0; j < grid[0].size(); ++ j) {
				if (grid[i][j] == '1') {
					res ++;
					dfshelper(grid, {i, j});
				}
			}
		}
		return res;
	}

	void dfshelper(vector<vector<char>>& grid, pair<int, int> index) {
		int i = index.first;
		int j = index.second;
		grid[i][j] = '0';
		if (i-1 >= 0 && grid[i-1][j] == '1')
			dfshelper(grid, {i-1, j});
		if (j-1 >= 0 && grid[i][j-1] == '1')
			dfshelper(grid, {i, j-1});
		if (i+1 < grid.size() && grid[i+1][j] == '1')
			dfshelper(grid, {i+1, j});
		if (j+1 < grid[0].size() && grid[i][j+1] == '1')
			dfshelper(grid, {i, j+1});
	}
};

/* the idea: DFS is better, check a pointer, set it to 0, then keep look around and
 * do the recursive call unitl all its current around is 0 */
class Solution {
public:
	struct newpoint {
		char val;
		int hasParent = 0;
		pair<int , int> parent;
		newpoint(char val, int i, int j) {
			this->val = val;
			parent.first = i;
			parent.second = j;
			hasParent = 0;
		}
	};

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
    	int row = grid.size(), col = grid[0].size(), i = 0, j = 0, res = 0;
    	
    	vector<vector<newpoint>> new_grid (row, vector<newpoint>(col, newpoint('0', -1, -1)));
    	for (i = 0; i < row; i++) 
    		for (j = 0; j < col; j++) 
    			new_grid[i][j].val = grid[i][j];
    		
    	for (i = 0; i < row; i++) {
    		for (j = 0; j < col; j++) {
    			if (new_grid[i][j].val == '1' && new_grid[i][j].hasParent == 0) {
    				new_grid[i][j].hasParent = -1;
    				new_grid[i][j].parent.first = i;
    				new_grid[i][j].parent.second = j;
	    			unionNode(0, 0, i, j, new_grid);
	    		}
    		} 
    	}
    	
    	res = 0;
    	for (i = 0; i < row; i++) 
    		for (j = 0; j < col; j++) 
    			if (new_grid[i][j].hasParent == -1)
    				res ++;

    	return res;
    }

    void unionNode(int p_i, int p_j, int i, int j, vector<vector<newpoint>>& grid) {
    	int row = grid.size(), col = grid[0].size();
    	if (i >= 0 && i < row && j >= 0 && j < col) {
    		if (grid[i][j].hasParent == -1) {
    			unionNode(i, j, i+1, j, grid);
    			unionNode(i, j, i-1, j, grid);
    			unionNode(i, j, i, j+1, grid);
    			unionNode(i, j, i, j-1, grid);
    		}
			else if (grid[i][j].hasParent == 0 && grid[i][j].val == '1') {
				merge(grid[p_i][p_j], grid[i][j]);
				unionNode(i, j, i+1, j, grid);
    			unionNode(i, j, i-1, j, grid);
    			unionNode(i, j, i, j+1, grid);
    			unionNode(i, j, i, j-1, grid);
			}
		}		
    }

    void merge(newpoint& parent, newpoint& child) {
    	child.parent.first = parent.parent.first;
    	child.parent.second = parent.parent.second;
    	child.hasParent = 1;
    }
};

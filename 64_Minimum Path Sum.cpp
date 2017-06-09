class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int state[row][col];
        int i = 0, j = 0;

        for (i = 0; i < row; i++) {
        	for (j = 0; j < col; j++) {
        		state[i][j] = 0;
        		if (i == 0 && j == 0)  state[i][j] = grid[i][j];
        		else if (i == 0 && j > 0) state[i][j] = grid[i][j] + state[i][j-1];
    			else if (i > 0 && j == 0) state[i][j] = grid[i][j] + state[i-1][j];
				else state[i][j] = grid[i][j] + min(state[i-1][j], state[i][j-1]);
        	}
        }

        return state[row-1][col-1];
    }
};
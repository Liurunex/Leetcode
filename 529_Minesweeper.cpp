class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if (board[click[0]][click[1]] == 'M') {
			board[click[0]][click[1]] = 'X';
			return board;
		}
        helper(board, click);
        return board;
    }
    
    void helper(vector<vector<char>>& board, vector<int>& click) {
		int i = click[0], j = click[1];
		if (board[i][j] != 'E') return;
		vector<pair<int, int>> recursiveRun;
		int minecount = 0;
		if (i-1 >= 0 && j-1 >= 0) {
			recursiveRun.push_back(make_pair(i-1, j-1));
			if (board[i-1][j-1] == 'M')
				minecount ++;
		}
		if (i-1 >= 0) { 
			recursiveRun.push_back(make_pair(i-1, j));
			if (board[i-1][j] == 'M') 
				minecount ++;
		}
		if (i-1 >= 0 && j+1 < board[0].size()) {	
			recursiveRun.push_back(make_pair(i-1, j+1));
			if (board[i-1][j+1] == 'M') 
				minecount ++;
		}

		if (j-1 >= 0) {
			recursiveRun.push_back(make_pair(i, j-1));
			if (board[i][j-1] == 'M') 
				minecount ++;
		}
		if (j+1 < board[0].size()) {
			recursiveRun.push_back(make_pair(i, j+1));
			if (board[i][j+1] == 'M') 
				minecount ++;
		}
	
		if (i+1 < board.size() && j-1 >= 0) {
			recursiveRun.push_back(make_pair(i+1, j-1));
			if (board[i+1][j-1] == 'M') 
				minecount ++;
		}
		if (i+1 < board.size()) {
			recursiveRun.push_back(make_pair(i+1, j));
			if (board[i+1][j] == 'M') 
				minecount ++;
		} 
		if (i+1 < board.size() && j+1 < board[0].size()) {
			recursiveRun.push_back(make_pair(i+1, j+1));
			if (board[i+1][j+1] == 'M') 
				minecount ++;
		}
        
		if (minecount == 0) {
			board[i][j] = 'B';
			while (!recursiveRun.empty()) {
				vector<int> newclick;
				newclick.push_back(recursiveRun.back().first);
				newclick.push_back(recursiveRun.back().second);
                recursiveRun.pop_back();
				helper(board, newclick);
			}
		}
		else board[i][j] = minecount + '0';
	}
};

/*
notice you only need to check node == 'M' case, moreover, notice everytime in recursion you should first check whether you have go through the point
 */

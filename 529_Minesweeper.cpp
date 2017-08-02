class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int i = click[0], j = click[1];
		if (board[click[0]][click[1]] == 'M') {
			board[click[0]][click[1]] = 'X';
			return board;
		}
		vector<pair<int, int>> recursiveRun;
		int minecount = 0;
		if (i-1 >= 0 && j-1 >= 0 ) { 
			recursiveRun.push_back(make_pair(i-1, j-1));
			if (board[i-1][j-1] == 'M') 
				minecount ++;
		}
		if (i-1 >= 0 && board[i-1][j] == 'M') minecount ++; 
		if (i-1 >= 0 && j+1 < board[0].size() && board[i-1][j+1] == 'M') minecount ++;
		
		if (j-1 >= 0 && board[i][j-1] == 'M') minecount ++;
		if (j+1 < board[0].size() && board[i][j+1] == 'M') minecount ++;

		if (i+1 < board.size() && j-1 >= 0 && board[i+1][j-1] == 'M') minecount ++; 
		if (i+1 < board.size() && board[i+1][j] == 'M') minecount ++; 
		if (i+1 < board.size() && j+1 < board[0].size() && board[i+1][j+1] == 'M') minecount ++;

		if (!minecount) {
			board[i][j] = 'B';
			for (int i = 0; i < recursiveRun.size(); ++ i) {
				vector<int> newclick;
				newclick.push_back(recursiveRun[i].first);
				newclick.push_back(recursiveRun[i].second);
				updateBoard(board, newclick);
			}
		}
		else board[i][j] = minecount + '0';
		return board;
	}
};
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<pair<int, int>> lookaround { make_pair(1, 0), make_pair(-1, 0)
			, make_pair(0, 1), make_pair(0, -1), make_pair(1, 1)
			, make_pair(-1, -1), make_pair(-1, 1), make_pair(1, -1) };

		for (int i = 0; i < board.size(); ++ i) {
			for (int j = 0; j < board[0].size(); ++ j) {
				int live_neighbor = 0;
				for (int k = 0; k < lookaround.size(); ++k) {
					int row = i + lookaround[k].first;
					int col = j + lookaround[k].second;
					if (row >=0 && row < board.size() && col >= 0 && 
						col < board[0].size() && (board[row][col] == 1 
							|| board[row][col] == 2)) {
						live_neighbor ++;
					}
				}
				if (!board[i][j]){
					if (live_neighbor == 3) board[i][j] = 3;
					else board[i][j] = 0;
				}	
				else {
					if (live_neighbor < 2 || live_neighbor > 3)
						board[i][j] = 2;
					else board[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < board.size(); ++ i)
			for (int j = 0; j < board[0].size(); ++ j)
				board[i][j] %= 2;
	}
};

/* the problem here is we are required to do this in-palce, namely no extra space can be created;
 * under this circustance, we come up the idea of status recording
 * the idea: use some number to record the status-change, in detail, we use 0, 1, 2, 3 to record
 * the status of each node; the node has four cases: dead to dead, dead to live, live to dead, live
 * to live; based on this, we use even number and odd number to mark node's status changing: 0 stand
 * 0->0, 1 stand 1->1, 2 stand 1->0, 3 stand 0->1; once we mark the whole board as this way, we will
 * know what the true board should be after converting
 */

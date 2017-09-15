class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int res = 0;

		for (int i = 0; i < board.size(); ++ i) {
			for (int j = 0; j < board[0].size(); ++ j) {
				if (board[i][j] == 'X'
					&& (i-1 < 0 || (i-1 >= 0 && board[i-1][j] == '.')) 
					&& (j-1 < 0 || (j-1 >= 0 && board[i][j-1] == '.'))) 
					res ++;
			}
		}
		return res;
	}
};

/* the idea: simple, we don't need to consider the DFS or BFS, since the question said
 * there is no any invalid input, namely, all batteships inside the board are placed in
 * valid way. Knowing this will help on solve the quesion in O(n); What we should do is
 * just travel the board by counting the starter or battelship, that is the point where
 * [i-1][j] and [i][j-1] is both not X, 
 */

/* what we really should concer is the invalid case, recommnad reading on this link:
 * http://www.cnblogs.com/grandyang/p/5979207.html
 */

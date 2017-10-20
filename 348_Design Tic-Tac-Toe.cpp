class TicTacToe {
private:
	vector<int> rows, cols;
	int ldiag, rdiag, size;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n): ldiag(0), rdiag(0), size(n) {
        rows = vector<int> (n, 0);
        cols = vector<int> (n, 0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
	int move(int row, int col, int player) {
		int addwho = player == 1 ? 1:-1;
		rows[row] += addwho;
		cols[col] += addwho;
		ldiag += (row == col) ? addwho:0;
		rdiag += (row == size-1-col) ? addwho:0;

		return (abs(rows[row]) == size || abs(cols[col]) == size ||
		abs(ldiag) == size || abs(rdiag) == size) ? player:0;
	}
};
/* the idea: the intial idea of O(n^2) space is not best here; 
 * since the game determines wins when a player fill a whole row or
 * coloumn or diagonal wiht his own pieces, that make our decesion
 * easy to implememnt: we use two vectors to record all row and column
 * situation, and tow diagonal integer since there is only two possible
 * way to arcive the winning case in diagnal; then we mark +1 means palyer
 * 1 play , -1 means other side, so that we can reduce our solution into
 * the lower O(1) time and O(n) space
 */

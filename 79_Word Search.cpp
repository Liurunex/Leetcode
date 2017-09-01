class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
 		if (!board.size()|| !board[0].size() || !word.length()) return false;
 		vector<vector<int>> visit_map (board.size(), vector<int>(board[0].size(), 0));
    	for (size_t i = 0; i < board.size(); ++ i)
    		for (size_t j = 0; j < board[0].size(); ++ j)
    			if (helper(board, i, j, visit_map, 0, word)) return true;

        return false;
    }

    bool helper(vector<vector<char>> &board, int rol, int col, 
    	vector<vector<int>> &visit_map, int position, string &word) {
    	
    	if (position >= word.size()) return true;
    	if (rol < 0 || rol == board.size() || col < 0 || col == board[0].size() || 
    		board[rol][col] != word[position] || visit_map[rol][col]) return false;

		visit_map[rol][col] = 1;
    	position ++;
    	if (helper(board, rol-1, col, visit_map, position, word)) return true;   	
    	if (helper(board, rol+1, col, visit_map, position, word)) return true;
    	if (helper(board, rol, col-1, visit_map, position, word)) return true;
    	if (helper(board, rol, col+1, visit_map, position, word)) return true;
    	/* be careful you must set the visited status back to 0 after 4-direction travel */
    	visit_map[rol][col] = 0;
    	return false;
    }
};

/*
the idea is sample, mark each node as start point to check, we only need a extra visted graph
to store the visitng status, no need do something like KMP to reduce the check times 
 */
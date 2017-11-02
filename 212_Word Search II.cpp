class Solution {
private:
	struct Trie {
		int val;
		bool end;
		string strvalue;
		vector<Trie*> children;
		Trie(char nval): val(nval), end(false), strvalue(""), children(26, NULL) {}
	};

	void trieBuild(vector<string>& words) {
		for (string word:words) {
			Trie* node = wordsRoot;
			for (char charc:word) {
				int index = charc - 'a';
				if (!node->children[index])
					node->children[index] = new Trie(charc);
				node = node->children[index];
			}
			node->end = true;
			node->strvalue = word;
		}
	}

	void dfsBt(vector<vector<char>>& board, vector<vector<bool>>& visited,
		int row, int col, vector<string>& res, Trie* node, vector<vector<int>>& directions) {
		if (node->end) {
			res.push_back(node->strvalue);
			node->end = false;
			/* important so that we avoid duplicate traversal!
			 * no need for return */
		}
		
		visited[row][col] = true;
		for (auto direc:directions) {
			int nrow = row + direc[0], ncol = col + direc[1];
			if (nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size()
				&& !visited[nrow][ncol] && node->children[board[nrow][ncol]-'a']){
				dfsBt(board, visited, nrow, ncol, res, node->children[board[nrow][ncol]-'a'], directions);
			}
		}
		visited[row][col] = false;
	}

private:
	Trie* wordsRoot;

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
		wordsRoot = new Trie(' ');
		trieBuild(words);
		
		vector<string> res;
		vector<vector<int>> directions ({{0,1}, {0,-1}, {1,0}, {-1,0}});
		for (int i = 0; i < board.size(); ++ i) {
			for (int j = 0; j < board[0].size(); ++ j) {
				if (wordsRoot->children[board[i][j] - 'a'])
					dfsBt(board, visited, i, j, res, wordsRoot->children[board[i][j] - 'a'], directions);
			}
		}
		return res;
	}
};

/* the idea: the brute force with dfs backtracking cannot work here, using Trie to store all words, then
 * we do our dfs backtracking: for each position[i][j], we check if it is unvisited and it is in the trie's
 * children, if so we keep dfs, otherwise we should backtracking; notice the Trie Search will not terminate 
 * when meet with node -> end == true, consider overlap case: [“app”, “apple”]; BTW, Tire only need to implement
 * insert fucntion
 * The analysis: normal brute force cost O(n^2 * word_num * word_size), in Tire version, it is
 * O(n^2 * word_size)
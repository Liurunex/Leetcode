class Solution {
public:
	/* recurrence will cause runtime error since stack-overflow *
	void checkSurround(vector<vector<char>>& board, int i, int j, int &up, int &down, int &left, int &right,
		vector<pair<int, int>>& itsVertices, vector<vector<int>>& visited) {
		if (visited[i][j]) return;
		visited[i][j] = 1;
		itsVertices.push_back(make_pair(i, j));
		if (i-1 >= 0 && board[i-1][j] == 'O' && !visited[i-1][j]) {
			up = min(up, i-1);
			checkSurround(board, i-1, j, up, down, left, right, itsVertices, visited);
		}

		if (i+1 < board.size() && board[i+1][j] == 'O' && !visited[i+1][j]) {
			down = max(down, i+1);
			checkSurround(board, i+1, j, up, down, left, right, itsVertices, visited);
		}

		if (j-1 >= 0 && board[i][j-1] == 'O' && !visited[i][j-1]) {
			left = min(left, j-1);
			checkSurround(board, i, j-1, up, down, left, right, itsVertices, visited);
		}

		if (j+1 < board[0].size()-1 && board[i][j+1] == 'O' && !visited[i][j+1]) {
			right = max(right, j+1);
			checkSurround(board, i, j+1, up, down, left, right, itsVertices, visited);
		}
	}
	*/
	void Non_Recurrent_checkSurround(vector<vector<char>>& board, int i, int j, int &up, int &down, int &left, int &right,
		vector<pair<int, int>>& itsVertices, vector<vector<int>>& visited) {

		stack<pair<int, int>> dfs_stack;
		dfs_stack.push(make_pair(i, j));
		visited[i][j] = 1;

		while (!dfs_stack.empty()) {
			i = dfs_stack.top().first;
			j = dfs_stack.top().second;
			dfs_stack.pop();
			itsVertices.push_back(make_pair(i, j));

			if (i-1 >= 0 && board[i-1][j] == 'O' && !visited[i-1][j]) {
				up = min(up, i-1);
				visited[i-1][j] = 1;
				dfs_stack.push(make_pair(i-1, j));
			}

			if (i+1 < board.size() && board[i+1][j] == 'O' && !visited[i+1][j]) {
				down = max(down, i+1);
				visited[i+1][j] = 1;
				dfs_stack.push(make_pair(i+1, j));
			}

			if (j-1 >= 0 && board[i][j-1] == 'O' && !visited[i][j-1]) {
				left = min(left, j-1);
				visited[i][j-1] = 1;
				dfs_stack.push(make_pair(i, j-1));
			}

			if (j+1 < board[0].size() && board[i][j+1] == 'O' && !visited[i][j+1]) {
				right = max(right, j+1);
				visited[i][j+1] = 1;
				dfs_stack.push(make_pair(i, j+1));
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		if ((board.size() < 3) || (board.size() > 0 && board[0].size() < 3)) return;

		vector<vector<int>> visited (board.size(), vector<int> (board[0].size(), 0));
		vector<pair<int, int>> itsVertices;
		int up = INT_MAX, down = -1, left = INT_MAX, right = -1;

		for (int i = 1; i < board.size()-1; ++ i) {
			for (int j = 1; j < board[0].size()-1; ++ j) {
				if (board[i][j] == 'O' && !visited[i][j]) {
					up = i, down = i, left = j, right = j;
					Non_Recurrent_checkSurround(board, i, j, up, down, left, right, itsVertices, visited);
					if (up == 0 || down == board.size()-1 || left == 0 || right == board[0].size()-1)
						itsVertices.clear();
					for (pair<int, int> vertice : itsVertices)
						board[vertice.first][vertice.second] = 'X';
					itsVertices.clear();
					up = INT_MAX;
					down = -1;
					left = INT_MAX;
					right = -1;
				}
			}
		}
	}
};

class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		queue<pair<int, int>> bfs_queue;
		for (int i = 0; i < rooms.size(); ++ i)
			for (int j = 0; j < rooms[0].size(); ++ j)
				if (!rooms[i][j]) bfs_queue.push(make_pair(i, j));

		vector<pair<int, int>> four_direction {
			make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
		while (!bfs_queue.empty()) {
			pair<int, int> curpos = bfs_queue.front();
			bfs_queue.pop();
			for (auto move:four_direction) {
				int row = curpos.first + move.first;
				int col = curpos.second + move.second;
				if (row >= 0 && row < rooms.size() 
					&& col >= 0 && col < rooms[0].size() 
					&& rooms[curpos.first][curpos.second]+1 < rooms[row][col]) {
					rooms[row][col] = rooms[curpos.first][curpos.second]+1;
					bfs_queue.push(make_pair(row, col));
				}
			}
		}
	}
};

/*
initial idea: find all 0, start at 0, do BFS on whole matirx, update vlaue if avaliable,
	the shortcome is: large time compleixity, repeating workload
the idea: a variant BFS: we push all 0's positions to queue; keep pop front element from
queue, it is the current start point, we only take a look at its four directions to see
if its four neighbors hold bigger number than its own value plus one, once it's true, we
push that neighbor into the queue as our candiate starters; do this preocess until the
queue is empty; 
Notice: you don't need worry about -1 and INF case, since -1 is always lower than our
canidate value plus 1, it will not be pushed into queue, vice-versa 
 */
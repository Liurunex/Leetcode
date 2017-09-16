class Solution {
public:
	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		if (!maze.size() || !maze[0].size()) return true;
		
		queue<pair<int, int>> visit_queue;
		vector<pair<int, int>> moves {
			make_pair(0, -1), make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0)};
		//vector<vector<bool>> visit_map (maze.size(), vector<bool> (maze[0].size(), false));
        
        visit_queue.push(make_pair(start[0], start[1]));
        maze[start[0]][start[1]] = 2;
        
		while (!visit_queue.empty()) {
			pair<int, int> position = visit_queue.front();
			visit_queue.pop();
			if (position.first == destination[0] && position.second == destination[1])
				return true;
			
			for (int i = 0; i < moves.size(); ++ i) {
				int row = position.first, col = position.second;
				do {
					row += moves[i].first;
					col += moves[i].second;
				} while (row >= 0 && row < maze.size() && col >= 0 
					&& col < maze[0].size() && maze[row][col] != 1);

				row -= moves[i].first;
				col -= moves[i].second;

				if (!maze[row][col]) {
					visit_queue.push(make_pair(row, col));
                    maze[row][col] = 2;
                }
			}
		}
		return false;
	}
};

/* the idea is similar to 286 wall and gate, using BFS will work; the trick is: instead of updating 
 * next position by 1, we should update the position until it reach a obstacle or eadge, that is the
 * reason we use a while loop inside for; Moreover, we don't need to use visiting map to record visiting
 * stauts, just a value changed in maze will work
 */

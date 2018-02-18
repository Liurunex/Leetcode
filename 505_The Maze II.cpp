class Solution {
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		queue<pair<int, int>> go_visit;
		vector<pair<int, int>> directions {{1,0}, {-1,0}, {0,1}, {0,-1}};
		vector<vector<int>> dist (maze.size(), vector<int>(maze[0].size(), INT_MAX));

		go_visit.push({start[0], start[1]});
		dist[start[0]][start[1]] = 0;
		
		while (!go_visit.empty()) {
			auto position = go_visit.front();
			go_visit.pop();

			if (position.first == destination[0] && position.second == destination[1])
				continue;

			for (auto direc:directions) {
				int row = position.first, col = position.second;
				int cur_dist = dist[row][col], travel_counter = 0;
				
				while (row >= 0 && row < maze.size() && col >= 0
					&& col < maze[0].size() && !maze[row][col]) {
					travel_counter ++;
					row += direc.first;
					col += direc.second;
				} 
                row -= direc.first;
				col -= direc.second;
                travel_counter --;

                if (dist[row][col] == INT_MAX || dist[row][col] > cur_dist + travel_counter) {
                	dist[row][col] = cur_dist + travel_counter;
                	go_visit.push({row, col});
                }
			}
		}
		return dist[destination[0]][destination[1]] == INT_MAX ? -1:dist[destination[0]][destination[1]];
	}
};

/* the idea: similar to Maze I: BFS + visited_map(memorized): unlike the maze I, here we use traditional
 * visited_map, where the map stores the minimal distance from start to this point (dist_map). Our purpose 
 * is clear, use bfs starting from the start point, we count the distance to next position, if the new distance
 * to that point is less than the value stored in visited_map(dist_map), no matter if we have vistied this
 * point before, we should push this point into queue agian since it might lead to a shorter path to our
 * destination, NOTICE this point is different from the Maze I since we don't care about the path length, so
 * that we will never visit it agian on maze I!*/

class Solution {
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		queue<tuple<int, int, int>> go_visit;
		vector<pair<int, int>> directions {{1,0}, {-1,0}, {0,1}, {0,-1}};

		int res = INT_MAX;
		go_visit.push(make_tuple(start[0], start[1], 0));
		while (!go_visit.empty()) {
			auto position = go_visit.front();
			go_visit.pop();
			maze[get<0>(position)][get<1>(position)] = 2;
            //cout << "origin: " << get<0>(position) << " " << get<1>(position) << " -> " << get<2>(position) << endl;
			if (get<0>(position) == destination[0] && get<1>(position) == destination[1]) {
				res = min(res, get<2>(position));
				continue;
			}

			for (auto direc:directions) {
				int row = get<0>(position), col = get<1>(position);
				int travel_counter = 0;
				while (row >= 0 && row < maze.size() && col >= 0
					&& col < maze[0].size() && maze[row][col] != 1) {
					travel_counter ++;
					row += direc.first;
					col += direc.second;
				} 
                row -= direc.first;
				col -= direc.second;
                travel_counter --;
               // cout << row << "-" << col << endl;
				if (!maze[row][col])
					go_visit.push(make_tuple(row, col, get<2>(position)+travel_counter));
			}
		}
		return res == INT_MAX ? -1:res;
	}
};


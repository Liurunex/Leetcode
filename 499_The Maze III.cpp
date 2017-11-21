class Solution {
public:
	string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
		queue<pair<int, int>> go_visit;
		vector<tuple<int, int, string>> directions {make_tuple(1,0,"d"), make_tuple(-1,0,"u"), 
			make_tuple(0,1,"r"), make_tuple(0,-1,"l")};
		
		vector<vector<pair<int, string>>> dist (maze.size(), vector<pair<int, string>>(maze[0].size(), {INT_MAX, "z"}));

		go_visit.push({ball[0], ball[1]});
		dist[ball[0]][ball[1]].first = 0;
		dist[ball[0]][ball[1]].second = "";
		
		while (!go_visit.empty()) {
			auto position = go_visit.front();
			go_visit.pop();

			for (auto direc:directions) {
				int row = position.first, col = position.second;
				int cur_dist = dist[row][col].first, travel_counter = 0;
				string cur_str = dist[row][col].second;
				int meeted = 0;
				while (row >= 0 && row < maze.size() && col >= 0
					&& col < maze[0].size() && !maze[row][col]) {
					travel_counter ++;
					row += get<0>(direc);
					col += get<1>(direc);
					if (row == hole[0] && col == hole[1]) {
						meeted = 1;
						break;
					}
				} 
				if (!meeted) {
					row -= get<0>(direc);
					col -= get<1>(direc);
	                travel_counter --;
				}

                if (dist[row][col].first == INT_MAX || dist[row][col].first > cur_dist + travel_counter) {
                	dist[row][col].first = cur_dist + travel_counter;
                	dist[row][col].second = cur_str + get<2>(direc);
                	if (!meeted)
                		go_visit.push({row, col});
                }
                
                else if (dist[row][col].first == cur_dist + travel_counter && 
                	cur_str+get<2>(direc) < dist[row][col].second) {
                	dist[row][col].second = cur_str + get<2>(direc);
                	if (!meeted)
                		go_visit.push({row, col});
                }
			}
		}
		return dist[hole[0]][hole[1]].second == "z" ? "impossible":dist[hole[0]][hole[1]].second;
	}
};
/* the idae: similar to Maze II, BFS + distance_map(memorized), the difference is we add additional path information into the distance_map.
 * Another NOTICE is that Maze III reuqest the ball might stopped once it meet the target hole, that indicates instead of travealing down
 * to the boundary, we will stopped once meet the target hole. On the basis of that, we will break in the traveling while loop once we 
 * meet the hole and do not do the backward opeartion in this case. Moreover, we add the case when the new distance is same as previous one
 * but to comapring the lexicographically order the path up to this point, in this case, we might push this node into the queue since the
 * new path might lead to a smalller lexicographically order path.
 **/
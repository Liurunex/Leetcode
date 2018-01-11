class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		auto compare = [](pair<int, int> x, pair<int, int> y) -> bool {
			return (x.first > y.first);
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> tovisited (compare);
        
		vector<int> distance (N+1, INT_MAX);
        distance[0] = 0;
		unordered_map<int, unordered_map<int, int>> graph;

		for (int i = 0; i < times.size(); ++ i)
			graph[times[i][0]][times[i][1]] = times[i][2];
        
		tovisited.push({0,K});
		distance[K] = 0;
		
		while (!tovisited.empty()) {
			int node = tovisited.top().second;
			tovisited.pop();

			for (auto i = graph[node].begin(); i != graph[node].end(); ++ i) {
				if (distance[i->first] > distance[node] + i->second) {
					distance[i->first] = distance[node] + i->second;
					tovisited.push({distance[i->first], i->first});
				}
			}
		}

		int res = 0;
		for (int candidate:distance) {
            if (candidate == INT_MAX)
			    return -1;
			res = max(res, candidate);
		}
		return res;
	}
};

/* the idea: Dijstra Algorithm (priority_queue) + Hashmap. The question can basially transfer into the
 * question: find all shortest cost from sourse node to all others, which can be solved by Dijstra. The
 * first thing we gonna do is to build the graph, here we use the adjacent list thougths: that is we 
 * use hashmap to map the node to its directly connected nodes with the weights attached. After that, we
 * get into the Dijstra part, one thing is to overwrite the priority queue's comparator, that is done by
 * lambda function, take care of that! Then we just do a BFS based on priority queue, no need for visited
 * map, since we will keep updating the distance of a node various times!
*/
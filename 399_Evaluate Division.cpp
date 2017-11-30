class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, 
		vector<double>& values, vector<pair<string, string>> queries) {

		 unordered_map<string, vector<pair<string, double>>> edges;

		 for (int i = 0; i < equations.size(); ++ i) {
		 	edges[equations[i].first].push_back({equations[i].second, values[i]});
		 	edges[equations[i].second].push_back({equations[i].first, 1/values[i]});
		 }

		 vector<double> res;
		 for (int i = 0; i < queries.size(); ++ i) {
             //cout << "--------" << endl;
		 	string start = queries[i].first, end = queries[i].second;
		 	double val = -1;
		 	if (edges.count(start) && edges.count(end)) {
		 		if (start == end) val = 1;
		 		else {
		 			queue<pair<string, double>> visit_queue;
                    unordered_set<string> visited;
		 			visit_queue.push({start, 1});
		 			while (!visit_queue.empty()) {
		 				auto node = visit_queue.front();
		 				//cout << node.first << endl;
                        visit_queue.pop();
                        visited.insert(node.first);
		 				if (node.first == end) {
		 					val = node.second;
		 					break;
		 				}
                        if (!edges.count(node.first))
                            continue;
		 				for (auto next:edges[node.first]) {
                            if (!visited.count(next.first))
		 					    visit_queue.push({next.first, node.second * next.second});
		 				}

		 			}
		 		}
		 	}
		 	else val = -1;
		 	res.push_back(val);
		 }

		 return res;
	}
};

/* the idea: Graph BFS + Adjacent list + vistied map. We first transfer the question into a graphs 
 * traversal question: that is, each ratio can be represented by two edges a->b and b->a. We built 
 * a graph using double linekd adjacent list based on this. NOTICE: the cycle issue: we can prove that 
 * if there is a cycle existed, BFS we first find the directly ratio between the start and end value of 
 * the cycle, this is beacuse the mathmatics can only allowed one resolution between two nodes! Then we 
 * do the BFS for each query, the trick part is: NOTICE TO SET a VISITED SET to avoid cycle visiting 
 * between adjacent nodes!
 */

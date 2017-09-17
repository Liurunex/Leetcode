class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> indegrees (numCourses, 0);
		vector<vector<int>> adjacent_list (numCourses, vector<int>(0));

		queue<int> zeroQueue;
		for (auto repre:prerequisites) {
			indegrees[repre.first] ++;
			adjacent_list[repre.second].push_back(repre.first);
		}

		for (int i = 0; i < numCourses; ++ i)
			if (!indegrees[i])
				zeroQueue.push(i);

		while (!zeroQueue.empty()) {
			int node = zeroQueue.front();
			zeroQueue.pop();
			for (int connectNode:adjacent_list[node])
				if(!(-- indegrees[connectNode]))
					zeroQueue.push(connectNode);
		}

		for (int i = 0; i < numCourses; ++ i)
			if (indegrees[i])
				return false;
		return true;
	}
};

/* the idea: we want to find out if there is a cycle inside the graph; the way
 * we do here is using th indegree idea: that is we built this graph storing in
 * adjacaent list, inital a a indegree map to recording the number of nodes point
 * to the single node; then we maintan a 0-degree queue which stores all nodes
 * with indegree zero, and those nodes indside the 0-degree queue indicates they
 * are the start of each independ subgraph; 
 * after preparing those process, we do our job: pop out the nodes indes 0-degree
 * queue, check thier adjacent nodes in adjacent list, devrease those connecting 
 * nodes' indegree vlaue by 1, if the indegree == 0, push this connecting node
 * inde the queue, keep doing this until the queue is empty;
 * after doing this, we should find all the indegree vlaues shoule be 0 if there
 * is no cycle, othterwise the graph has cycles
 */

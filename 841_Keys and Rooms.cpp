class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int num = rooms.size();
		unordered_set<int> reachable;
		unordered_set<int> visited;

		return dfs(0, rooms, reachable, visited);
	}

	bool dfs(int index, vector<vector<int>>& rooms, 
		unordered_set<int>& reachable, unordered_set<int>& visited) {
        reachable.insert(index);
        visited.insert(index);
		
        for (int i:rooms[index])
			reachable.insert(i);

		if (reachable.size() == rooms.size())
			return true;
		bool res = false;
		for (int i:rooms[index]) {
			if (!visited.count(i))
				res = res || dfs(i, rooms, reachable,visited);
		}

		return res;
	}
};
// DFS enough
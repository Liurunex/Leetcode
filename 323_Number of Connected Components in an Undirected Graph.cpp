class Solution {
public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		unordered_map<int, int> unionmap;
		int res = 0;
		for (int i = 0; i < n; i ++)
			unionmap[i] = i;

		for (auto edge:edges) {
			int root_1 = unionfind(unionmap, edge.first);
			int root_2 = unionfind(unionmap, edge.second);
			if (root_1 == root_2) continue;
			unionmerge(unionmap, root_1, root_2);
		}
		unordered_set<int> allcomp;
		for (auto i = unionmap.begin(); i != unionmap.end(); ++ i) {
			int itsroot = unionfind(unionmap, i->second);
			allcomp.insert(itsroot);
		}
		return allcomp.size();
	}

	int unionfind(unordered_map<int, int>& unionmap, int node) {
		if (unionmap[node] == node) return node;
		return unionfind(unionmap, unionmap[node]);
	}

	void unionmerge(unordered_map<int, int>& unionmap, int node_1,
		int node_2) {
		int root_1 = unionfind(unionmap, node_1);
		int root_2 = unionfind(unionmap, node_2);

		if (root_1 > root_2)
			unionmap[root_2] = root_1;
		else unionmap[root_1] = root_2;
	}

};
/* the idea: basically it's a union find a problem, notice to determine the parent and
 * child relation and to count the totally "root" number of all nodes
 * THINK ABOUT DFS or BFS to solve this problem
 */

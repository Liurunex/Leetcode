class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		unordered_map<int, int> union_parent;

		for (vector<int> pairs:edges) {
			union_parent[pairs[0]] = pairs[0];
            union_parent[pairs[1]] = pairs[1];
        }

		for (auto pairs:edges) {
			if (union_find(union_parent, pairs[0]) == union_find(union_parent, pairs[1])) {
				return pairs;
			}
			union_merge(union_parent, pairs[0], pairs[1]);
		}
		return {};
	}

	int union_find(unordered_map<int, int>& union_parent, int node) {
		if (union_parent[node] == node) return node;
		return union_find(union_parent, union_parent[node]);
	}

	void union_merge(unordered_map<int, int>& union_parent, int node_1, int node_2) {
		int root_1 = union_find(union_parent, node_1);
    	int root_2 = union_find(union_parent, node_2);

    	union_parent[root_2] = root_1;
	}

};

/* the idea: union-find, use the disjoin set and you are done, no need to
 * set the rank
 */

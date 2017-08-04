class Solution {
public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		vector<int> parentslist (n, -1);
		vector<int> govisit;
		for (int i = 0; i < edges.size(); ++ i) {
			int parent = min(edges[i].first, edges[i].second);
			int child  = max(edges[i].first, edges[i].second);

			if (parentslist[child] != -1 && parentslist[parent] != -1) {
				if (parentslist[child] == parentslist[parent]) continue;
				int newparent         = min (parentslist[child], parentslist[parent]);
				int newchild          = max (parentslist[child], parentslist[parent]);
				parentslist[child]    = newparent;
				parentslist[parent]   = newparent;
				parentslist[newchild] = newparent;
				continue;
			} 
			if (parentslist[child] != -1) {
				int newparent         = min(parentslist[child], parent);
				int newchild          = max(parentslist[child], parent);
				parentslist[child]    = newparent;
				parentslist[newchild] = newparent;
				continue;
			}
			if (parentslist[child] == parent) continue;
			if (child != parent) {
				parentslist[child] = parent;
				govisit.push_back(child);
			}
		}
		
		for (int i = 0; i < govisit.size(); ++ i) {
			int child = govisit[i];
			while (parentslist[child]!= -1) {
				child = parentslist[child];
				if (govisit[i] == parentslist[child]) {
					child = -1;
					break;
				}
			}
			parentslist[govisit[i]] = child;
		}

		int counter = 0;
		for (int i = 0; i < parentslist.size(); ++ i) {
			cout << parentslist[i] << " ";
			counter += parentslist[i] == -1 ? 1:0;
		}
		return counter;
	}
};
/* it can only solve the directed graph */
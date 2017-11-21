class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		if (start.size() != end.size()) return -1;
		unordered_set<string> dict (bank.begin(), bank.end());
        string genes = "ACGT";
		if (!dict.size() || !dict.count(end)) return -1;
		int res = INT_MAX, thesize = start.size();

		queue<pair<string, int>> bfsqueue;
		bfsqueue.push({start, 0});

		while (!bfsqueue.empty()) {
			auto word = bfsqueue.front();
			bfsqueue.pop();
			
			//cout << word.first << endl;
			if (word.first == end)
				return word.second;
			
			for (int i = 0; i < thesize; ++ i) {
				char tem = word.first[i];
				for (int j = 0; j < genes.size(); ++ j) {
					if (genes[j] == word.first[i])
						continue;
					
					word.first[i] = genes[j];
                    //cout << "candidate: " << word.first << " count-> " << dict.count(word.first) << endl;
					if (dict.count(word.first)) {
						bfsqueue.push({word.first, word.second+1});
						dict.erase(word.first); // avoid circle case
					}
					word.first[i] = tem;
				}
			}
		}
        return -1;
	}
};
/* the idea: same as word loader, which is BFS + backtracking, NOTICE 
 * 1.why can we erase the visited node from set instead of using visiting map but still ensure the correclation:
 * as we use BFS, if there is a node we have visited before will be visited afterward, that means the *second visit is redundant* 
 * and it is *not the optimal solution* in this case.
 * 2.why we can return at first time we find the target:
 * because we use bfs instead of dfs, that means the first time we find our target, we have 
 * reach it with the minimum cost of DFS */
 
 class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		if (start.size() != end.size()) return -1;
		unordered_set<string> dict (bank.begin(), bank.end());
		if (!dict.size() || !dict.count(end)) return -1;
		string genes = "ACGT";
		unordered_set<string> visit_map;
		int res = INT_MAX, thesize = start.size();

		queue<pair<string, int>> bfsqueue;
		bfsqueue.push({start, 0});

		while (!bfsqueue.empty()) {
			auto word = bfsqueue.front();
			bfsqueue.pop();
			visit_map.insert(word.first);
			
			//cout << word.first << endl;
			if (word.first == end)
				return word.second;
			
			for (int i = 0; i < thesize; ++ i) {
				char tem = word.first[i];
				for (int j = 0; j < genes.size(); ++ j) {
					if (genes[j] == word.first[i])
						continue;
					
					word.first[i] = genes[j];
                    //cout << "candidate: " << word.first << " count-> " << dict.count(word.first) << endl;
					if (dict.count(word.first) && !visit_map.count(word.first))
						bfsqueue.push({word.first, word.second+1});
					word.first[i] = tem;
				}
			}
		}
        return -1;
	}
};
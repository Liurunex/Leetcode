class Solution {
public:
	string alienOrder(vector<string>& words) {
		if (words.size() == 1) return words[0];
		map<char, set<char>> outlist;
		map<char, int> indegree;
		// build the graph
		for (int i = 0; i < words.size()-1; ++ i) {
			// add all letter into indegree map for graph
			for (int j = 0; j < words[i].size(); ++ j)
                if (!indegree.count(words[i][j]))
				    indegree[words[i][j]] = 0;

			int j = 0;
			while (j < words[i].size() && j < words[i+1].size()) {
				if (words[i][j] != words[i+1][j]) {
					// the edge is already counted, skip it
					if (outlist.count(words[i][j]) && outlist[words[i][j]].count(words[i+1][j]))
						break;
					indegree[words[i+1][j]] ++;
					outlist[words[i][j]].insert(words[i+1][j]);
					break;
				}
				j ++;
			}
		}
		// the last word has not yet added all its letters into the indegree map for graph
        for (int j = 0; j < words[words.size()-1].size(); ++ j)
            if (!indegree.count(words[words.size()-1][j]))
				indegree[words[words.size()-1][j]] = 0;
        
		string res;
		int n = indegree.size();        
        queue<char> govisit;
		vector<int> visited (26, 0);
		// BFS topological traversal
		findZeroIndegree(indegree, govisit, visited, res);
		while (!govisit.empty()) {
			char node = govisit.front();
			govisit.pop();
			for (auto tar = outlist[node].begin(); tar != outlist[node].end(); ++ tar )
				indegree[*tar] --;
			findZeroIndegree(indegree, govisit, visited, res);
		}

		return res.size() == n ? res:"";
	}

	void findZeroIndegree(map<char, int> &indegree, queue<char> &govisit, vector<int> &visited, string& res) {
		for (auto i = indegree.begin(); i != indegree.end(); ++ i) {
			if (i->second == 0 && !visited[i->first - 'a']) {
				visited[i->first - 'a'] = 1;
				res += i->first;
				govisit.push(i->first);
			}
		}
	}
};
/* the idea: topological sort + graph build + BFS; Similar to the Course Scheduler, we use the topological sort here.
 * First to build the graph. Since the words are sorted in Alien order, we need to compare each two adjacent words to
 * build the graph: that is, we compare the two to find the first different letters, which formed the edge for our graph.
 * Therefore we can update the indegree and edge records. Notice that we should add all not-involved letter with indegree = 0
 * into our graph, otherwise the graph is incomplete. Secondly we use BFS + topoligcal sort to traversal the graph: that is, 
 * push all 0-indegree nodes into queue, visited them and remove the edges started from those nodes, reduced the indegree of 
 * their corresponding connectors on the other side, repeat the process until there is no more 0-indegree nodes produced
*/

class Solution {
public:
	string alienOrder(vector<string>& words) {
		// build the graph
		if (words.size() == 1) return words[0];
		map<char, set<char>> outlist;
		map<char, int> indegree;

		for (int i = 0; i < words.size()-1; ++ i) {
			int j = 0;
			while (j < words[i].size() && j < words[i+1].size()) {
				if (words[i][j] == words[i+1][j]) {
					if (!indegree.count(words[i][j]))
                        indegree[words[i][j]] = 0;
                    j ++;
                    continue;
				}
				// circle case
                if (outlist.count(words[i+1][j]) && outlist[words[i+1][j]].count(words[i][j]))
                    return "";
                // edge already count
                if (outlist.count(words[i][j]) && outlist[words[i][j]].count(words[i+1][j])) {
                    j ++;
                    break;
                }
                indegree[words[i+1][j]] ++;
                if (!indegree.count(words[i][j]))
                    indegree[words[i][j]] = 0;
                outlist[words[i][j]].insert(words[i+1][j]);
                j ++;
                break;
			}
			// add rest letter into indegree map
			int jj = j;
			while (j < words[i].size()) {
				if (!indegree.count(words[i][j]))
                	indegree[words[i][j]] = 0;
                j ++;
			}
			while (jj < words[i+1].size()) {
				if (!indegree.count(words[i+1][jj]))
                    indegree[words[i+1][jj]] = 0;
                jj ++;
			}
		}

		string res;
		int n = indegree.size();
        queue<char> govisit;
		vector<int> visited (26, 0);

		findZeroIndegree(indegree, govisit, visited, res);
		while (!govisit.empty()) {
			char node = govisit.front();
			govisit.pop();
			for (auto tar = outlist[node].begin(); tar != outlist[node].end(); ++ tar )
				indegree[*tar] --;
			findZeroIndegree(indegree, govisit, visited, res);
		}

		return res.size() == n ? res:"";
	}

	void findZeroIndegree(map<char, int> &indegree, queue<char> &govisit, vector<int> &visited, string& res) {
		for (auto i = indegree.begin(); i != indegree.end(); ++ i) {
			if (i->second == 0 && !visited[i->first - 'a']) {
				visited[i->first - 'a'] = 1;
				res += i->first;
				govisit.push(i->first);
			}
		}
	}
};
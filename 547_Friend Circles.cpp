
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> roots (M.size(), 0);
        for (int i = 0; i < M.size(); ++ i)
            roots[i] = i;
        int res = M.size();
        for (int i = 0; i < M.size(); ++ i) {
            for (int j = i+1; j < M.size(); ++ j) {
                if (M[i][j]) {
                    int root_1 = union_found(roots, i);
                    int root_2 = union_found(roots, j);
                    if (root_1 != root_2) {
                        res --;
                        roots[root_1] = root_2;
                    }
                }
            }
        }
        return res;
    }
    
    int union_found(vector<int>& roots, int i) {
        if (i != roots[i])
            return union_found(roots, roots[i]);
        return i;
    }
};
// Union Found solution above
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		if (!M.size()) return 0;
		int res = 0;
		queue<int> bfsqueue;
		vector<bool> visited (M.size(), false); 
		bfsqueue.push(0);

		for (int i = 0; i < M.size(); ++ i) {
			if (visited[i]) continue;
			res ++;
			bfsqueue.push(i);
			while (!bfsqueue.empty()) {
				int theperson = bfsqueue.front();
				bfsqueue.pop();
				if (visited[theperson])
					continue;
				visited[theperson] = true;

				for (int i = 0; i < M[0].size(); ++ i) {
					if (M[theperson][i])
						bfsqueue.push(i);
				}
			}
		}

		return res;
	}
};
/* the idea: basically a BFS/DFS problem, can also be sloved by Union-Find;
 * we first need a visited map to reocrd all persons we have visited; the process
 * is we check each person, do a BFS to find his firend circle: that is BFS queue first
 * go check all his direct freiends, then his indirect friends until we queue bebecome
 * empty; repeat this process unitl we have visited all people;
 * CHECK: DFS solution is at the end
 */
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		if (!M.size()) return 0;
		int res = 0;
		queue<pair<int, int>> bfsqueue;

		for (int i = 0; i < M.size(); ++ i) 
			checked.insert(i);
			for (int j = 0; j < M[0].size(); ++ j)
				if (M[i][j])
					bfsqueue.push({j, i});
			if (bfsqueue.size() > 0) res ++;
			bfshelper(M, bfsqueue);
		}
		return res;
	}

	void bfshelper(vector<vector<int>>& M, 
		queue<pair<int, int>>& bfsqueue) {
		
		while (!bfsqueue.empty()) {
			int thefriend = bfsqueue.front().first;
			int theperson = bfsqueue.front().second;
			bfsqueue.pop();

			M[theperson][thefriend] = 0;
			M[thefriend][theperson] = 0;
			if (theperson == thefriend) continue;
			for (int j = 0; j < M[0].size(); ++ j) {
				if (M[thefriend][j])
					bfsqueue.push({j, thefriend});
			}
		}
	}
};
/* DFS solution */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            helper(M, i, visited);
            ++res;
        }
        return res;
    }
    void helper(vector<vector<int>>& M, int k, vector<bool>& visited) {
        visited[k] = true;
        for (int i = 0; i < M.size(); ++i) {
            if (!M[k][i] || visited[i]) continue;
            helper(M, i, visited);
        }
    }
};

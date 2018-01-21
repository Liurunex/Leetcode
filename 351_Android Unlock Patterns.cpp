class Solution {
public:
	int numberOfPatterns(int m, int n) {
		vector<vector<int>> connect (10, vector<int> (10, 0));
		connect[1][3] = connect[3][1] = 2;
	
		connect[1][7] = connect[7][1] = 4;
		connect[3][9] = connect[9][3] = 6;
		connect[7][9] = connect[9][7] = 8;

		connect[3][7] = connect[7][3] = 
		connect[1][9] = connect[9][1] = 
		connect[2][8] = connect[8][2] = 
		connect[4][6] = connect[6][4] = 5;

		int res = 0, counter = 0;
		vector<int> visited(10, 0);
		
        dfsBactracking(1, 1, m, n, counter, visited, connect);
		res += 4 * counter;
		counter = 0;
        
        dfsBactracking(2, 1, m, n, counter, visited, connect);
        res += 4 * counter;
        counter = 0;

		counter = 0;
		dfsBactracking(5, 1, m, n, counter, visited, connect);
        res += counter;
        
		return res;
	}

	void dfsBactracking(int root, int len, int& m, int& n, int& counter,
		vector<int>& visited, vector<vector<int>>& connect) {
        if (len ++ >= m)
			counter ++;
        if (len > n) return;
        
        visited[root] = 1;
        for (int i = 1; i < 10; ++ i) {
            if (i == root) continue;
			int connector = connect[root][i];
			if (!visited[i] && (!connector || visited[connector])) {
                //cout << "root: " << root << " -> " << i << endl;
				dfsBactracking(i, len, m, n, counter, visited, connect);
			}
		}
		visited[root] = 0;
	}
};

/* the idea: DFS + Backtracking; We notice that graph has symmetric structure, that is
 * starting at 1 is same as 3, 7, 9, while starting at 2 is same as 4, 6, 8. So that we 
 * only need do 3 times DFS on 1, 2, 5. For the DFS backtracking process, we need a visited
 * map to determine which number has been visited so that we avoid visiting it again to make
 * infinite loop. Meanwhile, there are invalid cases for moving, that is, two numbers are not
 * adjacent to each other( NOTICE that 1 and 6 is adjacent since it's Andorid!). In that invaild
 * case, the only way to valid it is that the number connect those two targets has been visited,
 * so that we cando the move on those two non-adjacent number, that's the reason why we need a 
 * 2-dimension connect vector to determine whether two number is adjacent or connect by which number
 * */
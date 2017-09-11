class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
		vector<vector<int>> pacific_touch 
			(matrix.size(), vector<int> (matrix[0].size(), 0));		
		vector<vector<int>> altantic_touch
			(matrix.size(), vector<int> (matrix[0].size(), 0));
		queue<pair<int, int>> pacific_queue;
		queue<pair<int, int>> altantic_queue;

		for (int i = 0; i < matrix.size(); ++ i) {
			pacific_touch[i][0] = 1;
			pacific_queue.push(make_pair(i, 0));
			altantic_touch[i][matrix[0].size()-1] = 1;
			altantic_queue.push(make_pair(i, matrix[0].size()-1));
		}
		for (int i = 0; i < matrix[0].size(); ++ i) {
			pacific_touch[0][i] = 1;
			if (i != 0) pacific_queue.push(make_pair(0, i));
			altantic_touch[matrix.size()-1][i] = 1;
			if (i != matrix[0].size()-1) 
				altantic_queue.push(make_pair(matrix.size()-1, i));
		}
        /*
        cout << "origin:" << endl;
        for (int i = 0; i < matrix.size(); ++ i) {
                for (int j = 0; j < matrix[0].size(); ++ j) {
                    cout << pacific_touch[i][j] << " ";
                }
            cout << endl;
        }*/
        
		bfsfind(matrix, pacific_queue, pacific_touch);
		bfsfind(matrix, altantic_queue, altantic_touch);
        /*
        cout << "after:" << endl;
        for (int i = 0; i < matrix.size(); ++ i) {
                for (int j = 0; j < matrix[0].size(); ++ j) {
                    cout << pacific_touch[i][j] << " ";
                }
            cout << endl;
        }
        */
		vector<pair<int, int>> res;
		for (int i = 0; i < matrix.size(); ++ i)
			for (int j = 0; j < matrix[0].size(); ++ j)
				if (altantic_touch[i][j] == pacific_touch[i][j] && altantic_touch[i][j])
					res.push_back(make_pair(i, j));
		return res;
	}

	void bfsfind(vector<vector<int>>& matrix, queue<pair<int, int>> bfdqueue,
		vector<vector<int>> & ocean_touch) {
		vector<pair<int, int>> four_direction { 
		 	make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), 
		 	make_pair(0, -1)};
		while (!bfdqueue.empty()) {
			pair<int, int> curpos = bfdqueue.front();
			bfdqueue.pop();
			for (auto move:four_direction) {
				int row = curpos.first + move.first;
				int col = curpos.second + move.second;
				if (row >= 0 && row < matrix.size() 
					&& col >= 0 && col < matrix[0].size() 
					&& ocean_touch[row][col] != 1 &&
					matrix[curpos.first][curpos.second] <= matrix[row][col]) {
					ocean_touch[row][col] = 1;
					bfdqueue.push(make_pair(row, col));
				}
			}
		}
		
	}
};

/*
the idea is acutally same as Walls and Gates(286), BFS; 
but it is brilliant that we consider the question in reversed way: the
question ask for the point could flow to both oceans, as the initial 
idea will be set each node as the water spring source,
do the DFS on each node in matrix which had hight time 
complecity; however here we found a better way by reverse the question: 
that is we start from the ocean side to consider: we concern those points
can be connected by ocean if water flow from low to high, this idea make
the implementation easier to do. THE HINT IS: Conisder the Reverse Side of
a question if you find it hard from front side
 */
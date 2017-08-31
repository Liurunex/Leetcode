class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> colrec;
		vector<vector<string>> res;
		vector<string> solution(n, string(n, '.'));
		solveHelper(res, colrec, solution, 0, n);
		return res;
	}

	void solveHelper(vector<vector<string>> &res, vector<int> colrec, 
		vector<string> &solution, int row, int limit) {
		if (row >= limit) {
			res.push_back(solution);
			return;
		}
		
		for (int i = 0; i < limit; ++ i) {
			int valid = 1;
			for (int j = 0; j < colrec.size(); j ++){
				if (colrec[j] == i || (abs(colrec[j]-i) == abs(j-row))) {
					valid = 0;
					break;
				}
			}
			/* do the next row calling */
			if (valid) {
				solution[row][i] = 'Q';
				colrec.push_back(i);
				solveHelper(res, colrec, solution, row+1, limit);
				colrec.pop_back();
				solution[row][i] = '.';
			}
		}

	}
};

/* the idea is same as N-Queen II, only to attacked a extra vector<stirng> to store the board 
current stauts; to improve the runing perfermance, we can pass a empty board into recusive call 
since the orginal one attacked with whole board will cost much time on passing by refereence */
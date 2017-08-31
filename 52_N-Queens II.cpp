class Solution {
public:
	int totalNQueens(int n) {
		int res = 0;
		vector<int> colrec;
		nQueensHelper(res, colrec, n, 0);
		return res;
	}

	void nQueensHelper(int &res, vector<int> &colrec, int limit, int row) {
		if (row == limit) {
			res ++;
			return; 
		}

		for (int cur_col = 0; cur_col < limit; ++ cur_col) {
			/* judege if the position is valid */
			int valid = 1;
			for (int i = 0; i < colrec.size(); ++ i) {
				if (colrec[i] == cur_col || abs(row-i) == abs(cur_col-colrec[i])) { 
					valid = 0; break; 
				}
			}

			/* if valid, add the current position into vector, recursively calling next row;
			notice we must pop the current position out after the recursive call*/
			if (valid) {
				colrec.push_back(cur_col);
				nQueensHelper(res, colrec, limit, row+1);
				colrec.pop_back();
			}
		}

	}
};

/*
the idea is backtracking, that is: we use a 1-d array colrec to record the coloum position, where 
colrec[i] stores the column of queen placed on ith row; 
on each recursive call, we actually go through all coloumn posibilities of the queen on ith row; we
operate a inspection process for current column to check whether it was valid (column conflicts, digional 
conflicts), once it is valid, we stores the column into colrec and then proceed to next row recursive calls
keep in mind that we must pop out the stored column number when we go back from its next recursive calls
 */
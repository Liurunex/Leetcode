class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex <= 0) return {};
		vector<int> res (rowIndex, 0);
		res[0] = 1;
		for (int i = 1; i < rowIndex; ++ i)
			for (int j = i; j > 0; -- j)
				res[j] += res[j-1];
		return res;
	}
};
/* the idea is rolling array instead of storing
 * all rows. that is we keep tracking of a 
 * array with rowIndex+1 size, and we sum up
 * the rows from 1 to rowIndex; the relation
 * of pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
 * namely our last arrays stores the element of i-1th row
 * so taht we can untilize that for our current ith row;
 * NOTICE: the inner must be bolltem up construct for
 * the sake of avoiding the redunadent computing
 */

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		for (int start = 0; start < matrix.size()/2; ++ start) {
			int boundary = matrix.size()-1-start;

			for (int j = 0; j < boundary-start; ++ j ) {
				int tem                      = matrix[start][start+j];
				matrix[start][start+j]       = matrix[boundary-j][start];
				matrix[boundary-j][start]    = matrix[boundary][boundary-j];
				matrix[boundary][boundary-j] = matrix[start+j][boundary];
				matrix[start+j][boundary]    = tem;
			}

		}
	}
};
/* the idea: rotate the squre layer by layer, that is from outmost to inner;
 * the rotate order is upper side replaced by left side, left side replaced by bottom,
 * bottom repalced by right side, right side replace by upper;
 * the trick is: the length is each layer should be carefully consider:
 *
 * start=i (i,i+j) ----------boundary=n-1-i; (i+j, boundary)
 * |						|
 * |						|
 * |							
 * (boundary-j, i)----------(boundary, boundary-j)

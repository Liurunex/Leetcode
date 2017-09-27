class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int i = matrix.size()-1, j = 0;
		while (i >= 0 && j < matrix[0].size()) {
			if (matrix[i][j] == target) return true;
			if (matrix[i][j] > target) i --;
			else j ++;
		}
		return false;
	}
};

/* the idea: this is O(m+n) solution; We start from upper right conrer
 * or bottom left corner one, let's focus on the left bottom conrer, 
 * we notice that in row its ascending from left to right, while in column
 * it's descending from bottom to upper; therefore we can push our alogrithm:
 * once the target is bigger than current value, move left, else move up until 
 * we find the target
 * /

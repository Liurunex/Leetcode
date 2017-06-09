class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int left = matrix[0][0], right = matrix[n-1][n-1], mid = 0;
		while (left < right) {
			int count = 0;
			mid = left + (right - left)/2;
			int i = n-1, j = 0;
			while (i >= 0 && j < n) {
				if (matrix[i][j] <= mid) {
					j ++;
					count += i + 1;
				}
				else i --;
			}

			if (count < k)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		if (ops.size() == 0) return m*n;
		int res = 0, a = 0, count = 0;
		int mm = INT_MAX, nn = INT_MAX;
		for (int i = 0; i < ops.size(); ++ i) {
			mm = min(ops[i][0], mm);
			nn = min(ops[i][1], nn);
		}

		return mm * nn;

	}
};

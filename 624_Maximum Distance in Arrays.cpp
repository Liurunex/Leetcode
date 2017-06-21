class Solution {
public:
	int maxDistance(vector<vector<int>>& arrays) {
		int res = 0;
		int curmin = arrays[0][0], curmax = arrays[0].back();
		for (int i = 1; i < arrays.size(); ++ i) {
			res = max(res, max(abs(arrays[i].back() - curmin), 
				abs(curmax - arrays[i][0])));
			curmin = min(curmin, arrays[i][0]);
			curmax = max(curmax, arrays[i].back());
		}
		return res;
	}
};

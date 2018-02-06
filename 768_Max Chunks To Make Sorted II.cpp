class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		if (!arr.size()) return 0;
		int left_max = arr[0], i = 1, res = 0;
		vector<int> rightMins (arr.size(), -1);
		rightMins.back() = arr.back();
		for (int i = arr.size()-2; i >= 0; -- i)
			rightMins[i] = min(rightMins[i+1], arr[i]);

		while (i < arr.size()) {
			
			if (left_max <= rightMins[i]) {
				res ++;
				left_max = INT_MIN;
			}
			left_max = max(left_max, arr[i]);
			i ++;
		}

		return ++res;
	}
};
/* the idea: greedy. 记每一个数其右边的min值，放入right_min，同样用greedy思路，
 * 记一个left_max，从左到右遍历，不断更新local_max, 当发现local_max <= right_min[i]的
 * 时候，说明右边那一块没有数小于左边，两边sorted后correct，可以分chunk，reset left_max.
 * NOTICE, left_max的update放在判断后，`[...].max ? [arr[i]...].min`，记着扫描完后
 * res要自增1，因为最后一个chunk没有算 
 * */
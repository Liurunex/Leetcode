class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int res = 0, i = 0, local_max = INT_MIN;
		while (i < arr.size()) {
			local_max = max(local_max, arr[i]);
			if (i == local_max) {
				res ++;
				local_max = INT_MIN;
			}
			++ i;
		}
		return res;
	}
};
/* the idea: Array. 限定了没有duplicate，数范围[0, n-1]和index范围一致，所以考虑
 * 累计：从左向右遍历，不断更新local_max，当发现目前index == local_max, 意味着目前
 * 向左边local_max已经找到了其正确的index，可以分出一个chunk, 此时reset local_max,
 * repeat until we travel all elements*/
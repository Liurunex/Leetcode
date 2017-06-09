class Solution {
public:
	int maxSubArrayLen(vector<int>& nums, int k) {
		int sum = 0, res = 0;
		unordered_map<int, int> sumToIndex;
		sumToIndex[0] = -1;
		for (int i = 0; i < (int)nums.size(); ++ i) {
			sum += nums[i];
			if (sumToIndex.find(sum) == sumToIndex.end())
			    sumToIndex[sum] = i;
			if (sumToIndex.find(sum - k) != sumToIndex.end())
				res = max(res, i - sumToIndex[sum-k]);
		}
		return res;
	}
};

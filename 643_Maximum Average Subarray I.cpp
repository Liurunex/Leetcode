class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int res = 0;
		for (int i = 0; i < k; i ++)
			res += nums[i];
		int pre = 0, presum = res;
		for (int i = k; i < nums.size(); ++ i) {
			int sum = presum - nums[pre] + nums[i];
			pre ++;
			res = max(res, sum);
			presum = sum;
		}
		return res/(double)k;
	}
};
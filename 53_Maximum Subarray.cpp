class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return INT_MIN;
		vector<int> dp (nums.size(), 0);
		dp[0] = nums[0];
		int maxres = dp[0];
		for (int i = 1; i < nums.size(); ++ i) {
			dp[i] = max(dp[i-1] + nums[i], nums[i]);
			maxres = max(maxres, dp[i]);
		}
		return maxres;
	}
};
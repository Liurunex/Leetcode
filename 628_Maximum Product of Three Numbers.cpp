class Solution {
	public:
    int maximumProduct(vector<int>& nums) {
		if (nums.size() < 3) return 0;
		sort(nums.begin(), nums.end());
		long long p1 = nums[0] * nums[1] * nums[nums.size()-1];
		long long p2 = nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
		return max(p1, p2);
	}
};

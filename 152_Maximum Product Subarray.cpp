class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int maxLocal = nums[0], minLocal = nums[0], global = nums[0];
		for (int i = 1; i < nums.size(); ++ i) {
			int tem = maxLocal;
			maxLocal = max(minLocal*nums[i], max(maxLocal*nums[i], nums[i]));
			minLocal = min(tem*nums[i], min(minLocal*nums[i], nums[i]));
			global = max(maxLocal, global);
		}
		return global;
	}
};

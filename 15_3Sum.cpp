class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return {};
		vector<vector<int>> res;
		int target = 0;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size()-2; ++ i) {
			if (i > 0 && nums[i-1] == nums[i]) continue;
			twoSum(nums, i+1, target - nums[i], res);
		}
		return res;
	}
	
	void twoSum(vector<int>& nums, int start_point, int target, vector<vector<int>>& res) {
		int minTry = start_point, maxTry = nums.size()-1;
		vector<int> bingo;
		while (minTry < maxTry) {
			int curSum = nums[minTry] + nums[maxTry];
			if (curSum == target) {
				bingo.clear();
				bingo.push_back(nums[minTry]);
				bingo.push_back(nums[maxTry]);
				bingo.push_back(nums[start_point-1]);
				res.push_back(bingo);
				while (nums[minTry] == nums[++ minTry]);
				while (nums[maxTry] == nums[-- maxTry]);
			}
			else if (curSum > target) maxTry --;
			else minTry ++;
		}
	}
};

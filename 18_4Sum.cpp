class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4) return {};
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < nums.size()-3; ++ i) {
			if (i > 0 && nums[i-1] == nums[i]) continue;
			vector<int> curres;
			curres.push_back(nums[i]);
			for (int j = i+1; j < nums.size()-2; ++ j) {
				if (j > i+1 && nums[j-1] == nums[j]) continue;
				curres.push_back(nums[j]);
				twoSumhelper(res, nums, curres, target-nums[i]-nums[j], j+1);
				curres.pop_back();
			}
			curres.pop_back();
		}
		return res;
	}

	void twoSumhelper(vector<vector<int>>& res, vector<int>& nums, 
		vector<int>& curres, int target, int start) {
		int left = start, right = nums.size()-1;
		while (left < right) {
			int cursum = nums[left]+nums[right];
			if (cursum == target) {
				curres.push_back(nums[left]);
				curres.push_back(nums[right]);
				res.push_back(curres);
				curres.pop_back();
				curres.pop_back();
				while (left < right && nums[left] == nums[++ left]);
				while (left < right && nums[right] == nums[-- right]);
			}
			else if (cursum > target) right --;
			else left ++;
		}
	}
};
/* the idea: just follow the 3Sum thougths; the trick here is we need eliminate the duplicates
 * not only for the last two sum, but also the first number, namely, the outer and inner for loop
 * should go to check if current nodes is a duplicate of previous one respectively; furthemore,
 * to judege the duplicate for i and j, we should start at the correct position boundary, be carefu!
 */

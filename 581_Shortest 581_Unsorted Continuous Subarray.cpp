class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size() <  2) return 0;
		int min = nums[0], max = nums[0], star = 0, end = 0;
		vector<int> sortNum(nums);
		sort(sortNum.begin(), sortNum.end());

		for (int i = 0; i < nums.size(); ++ i) {
			if (nums[i] != sortNum[i]) {
				star = i;
				break;
			}
		}

		for (int i = nums.size()-1; i >= 0; -- i) {
			if (nums[i] != sortNum[i]) {
				end = i;
				break;
			}
		}

		if (star == end) return 0;
		return (end-star+1) > 0 ? end-star+1 : 0;
	}
};

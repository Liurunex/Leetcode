class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int res = 0, sum = 0;
		for (int i = 0; i < nums.size(); ++ i) {
			if (nums[i]) sum ++;
			else {
				res = max(sum, res);
				sum = 0;
			}
		}
		return max(sum, res);
	}
};
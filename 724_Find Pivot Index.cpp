class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int sum = 0;
		for (int i:nums)
			sum += i;
		int presum = 0;
		for (int i = 0; i < nums.size(); ++ i) {
			if (!i) {
				if (!(sum-nums[i]))
					return i;
				continue;
			}
			presum += nums[i-1];
			if (presum == sum - presum - nums[i])
				return i;
		}

		return -1;
	}
};
/* the idea: two times O(n) loop, one find the sum, second 
 * iterate to find the possible position from left to right
 */
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) return 0;
		sort(nums.begin(), nums.end());
		int res = INT_MAX, sum = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size()-2; ++ i) {
			twoSum(nums, target, i+1, res, sum);
			if (!res) return target;
		}

		return sum;
	}
	void twoSum (vector<int>& nums, int& target, int start, int& res, int& sum) {
		int left = start, right = nums.size()-1;
		while (left < right) {
			int cursum = nums[start-1] + nums[left] + nums[right];
			int curdis = abs(cursum-target);
			sum = res > curdis ? cursum:sum;
			res = min(res, curdis);
			if (cursum == target) {
				res = 0;
				return;
			}
			else if (cursum > target)
				right --;
			else left ++;
		}
	}
};

/* the idea: much similar to 3Sum problem; we basically follow the same thougths, except we 
 * keep the target as original one; the thoughts is acutally to give a sorted travesal, that
 * is we pick up the first element, and then using two-pointer(left-right) method to comparing
 * the new sum to our target; NOTICE that we must sort the whole array first otherwise we will
 * not give the sorted traversal;
 */

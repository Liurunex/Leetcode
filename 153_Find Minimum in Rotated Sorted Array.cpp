class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return min(nums[0], nums[1]);
		int leftbound = 0;
		int rightbound = nums.size()-1;
		int minres = nums[0];
		if (nums[rightbound] > nums[leftbound]) return minres;
		while (leftbound <= rightbound) {
			int mid = leftbound + (rightbound-leftbound)/2;
			if (nums[mid] > minres)
				leftbound = mid+1;
			else {
				minres = nums[mid];
				rightbound = mid-1;
			}
		}
		return nums[leftbound];
	}
};

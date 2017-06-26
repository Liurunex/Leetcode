/* idea: since nums[-1] == nums[n] = -infinte, binary search will work: if current non-candiate node excess its left, then nodes in rigth side are candiates, and vice verse */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size()-1, mid = 0, 
			excessLeft = 0, excessRight = 0;
		while (left <= right) {
			excessLeft  = 1;
			excessRight = 1;
			mid = left + (right - left)/2;
			if (mid-1 >= 0 && nums[mid] < nums[mid-1])
				excessLeft  = 0;
			if (mid+1 < nums.size() && nums[mid] < nums[mid+1])
				excessRight = 0;
			if (excessLeft && excessRight) return mid;
			if (excessLeft) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}
};

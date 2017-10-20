class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size()-1;
		vector<int> bounder (2, -1);
		
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (nums[mid] == target) {
				if (mid > 0 && nums[mid] == nums[mid-1])
					right = mid-1;
				else {
					bounder[0] = mid;
					break;
				}
			}
			else if (nums[mid] > target) right = mid-1;
			else left = mid+1;
		}

		right = nums.size()-1;
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (nums[mid] == target) {
				if (mid < nums.size()-1 && nums[mid] == nums[mid+1])
					left = mid+1;
				else {
					bounder[1] = mid;
					break;
				}
			}
			else if (nums[mid] > target) right = mid-1;
			else left = mid+1;
		}

		return bounder;
	}
};
/* the idea: we want the leftmost and rightmost index of the target, 
 * so that we should do twice BS, that is the first one used to find
 * the leftmost index, we add the move condition in the case where
 * nums[mid] = target, so that we can keep moving in BS behavior to 
 * acheive the O(logn) time complexcity, the rightmost BS follow the
 * same policy
 */

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (!nums.size()) return -1;
		if (nums[0] == target) return 0;
 		int pivot_index = 0, res = 0;
		for (int i = 1; i < nums.size(); ++ i, ++ pivot_index) {
			if (pivot_index == nums.size()) break;
			if (nums[pivot_index] > nums[i]) break;
		}
		if (pivot_index >= nums.size()-1) return binary_search(nums, 0, nums.size()-1, target);
		if (target > nums[pivot_index] || target < nums[pivot_index+1]) return -1;
		if (target >= nums[pivot_index+1] && target <= nums[nums.size()-1])
			res = binary_search(nums, pivot_index+1, nums.size()-1, target);
		else res = binary_search(nums, 0, pivot_index, target);
		return res;
	}

	int binary_search(vector<int>& nums, int left, int right, int target) {
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (nums[mid] == target) return mid;
			if (nums[mid] > target) right = mid-1;
			else left = mid+1;
 		}
 		return -1;
	}
};

/*
the initial idea is find the pivot and do the binary search
 */

/* 
another smarter way: in total there are two cases: 
nums[start] > nums[end] > nums[mid] -> right half sorted, check which part target belong to
nums[mid] > nums[start] > nums[end] -> left half sort, check which part target belong to
speical base case about nums.size() == 2:
nums[mid] = nums[start] < nums[end], if: nums[mid] < target <= nums[end], then right half, vice verse
nums[mid] = nums[start] > nums[end], if: nums[start] <= target < nums[mid], then left half, vice verse
conclusion:
nums[mid] < nums[end]: right half sorted, check if target inside
nums[mid] > nums[start]: left half sorted, check if target insde
*/
class Solution {
public:
 	int search(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            
            if(nums[mid]==target) return mid;  
            
            if(nums[mid] < nums[right]) { // right half sorted
                if(target > nums[mid] && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
            else {  // left half sorted
                if(target >= nums[left] && target < nums[mid]) 
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return -1;
    }
};
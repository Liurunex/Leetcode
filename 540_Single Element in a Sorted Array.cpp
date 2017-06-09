class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	if (nums.size() < 2) return nums[0];
    	if (nums.size() % 2 == 0) return NULL;
        int leftbound = 0, rightbound = nums.size()-1;
        while (leftbound < rightbound) {
        	int mid = leftbound + (rightbound - leftbound)/2;
        	if (mid % 2 == 0) {
	        	if (nums[mid] == nums[mid-1]) 
	        		rightbound = mid - 2;
	        	else if (nums[mid] == nums[mid+1])
	        		leftbound = mid + 2;
	    		else return nums[mid];
	    	}
	    	/* last case for 3 elements */
	    	else {
	    		if (nums[mid] == nums[mid-1]) 
	        		leftbound = mid + 1;
	        	else if (nums[mid] == nums[mid+1])
	        		rightbound = mid - 1;
	    	}
        }
        return nums[leftbound];
    }
};
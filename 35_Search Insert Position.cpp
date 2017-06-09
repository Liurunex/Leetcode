class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int res;
        while(left <= right) {
        	int mid = (left+right)/2;
        	res = mid;
        	if (nums[mid] == target)
    			break;
    		else if (nums[mid] > target) 
    			right = mid -1;
    		else if (nums[mid] < target) {
    			left = mid +1;
    			res ++;
    		}
        }
        return res;
    }
};
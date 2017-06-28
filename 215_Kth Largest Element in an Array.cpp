/*
quick sort is the key: 
http://www.geeksforgeeks.org/quick-sort/
http://www.cs.yale.edu/homes/aspnes/pinewiki/QuickSelect.html
http://blog.csdn.net/morewindows/article/details/6684558
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size()-1;
		int index = quickSort(nums, left, right);
		
		while (index + k != nums.size()) {
			if (index + k > nums.size())
				right = index - 1;
			else left = index + 1;
			
			index = quickSort(nums, left, right);
		}
		return nums[index];
	}
    int quickSort(vector<int>& nums, int left, int right) {
    	int i = left, j = right, theOne = nums[left];
		while (i < j) {
    		while (i < j) {
				if (nums[j] < theOne) {
    				nums[i] = nums[j];
    				i ++;
					break;
    			}
				j --;
    		}
    		while (i < j) {
    			if (nums[i] > theOne) {
    				nums[j] =  nums[i];
    				j --;
					break;
    			}
    			i ++;
    		}
    	}
    	nums[i] = theOne;
		return i;
    }
};

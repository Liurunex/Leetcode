class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
 		int theOne = nums[0];      
    }
    int quickSort(vector<int>& nums) {
    	int i = 1, j = nums.size()-1, theOne = nums[0], theindex = 0;
    	while (i < j) {
    		while (1) {
    			if (nums[j] < theOne) {
    				nums[theindex] = nums[j];
    				theindex = j;
    				break;
    			}
    			j --; 
    		}
    		while (1) {
    			if (nums[i] > theOne) {
    				nums[theindex] == nums[i];
    				theindex = i;
    				break;
    			}
    			i ++;
    		}
    	}
    		
    }
};
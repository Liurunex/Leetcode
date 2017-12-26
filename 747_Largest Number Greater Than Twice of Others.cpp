class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int index  = nums[0] > nums[1] ? 0:1;
		int firmax = nums[0] > nums[1] ? nums[0]:nums[1];
		int secmax = nums[0] > nums[1] ? nums[1]:nums[0]; 
		
		if (nums.size() == 2)
			return secmax*2 <= firmax ? index:-1;
		

		for (int i = 2; i < nums.size(); ++ i) {
			if (nums[i] > firmax) {
				secmax = firmax;
				firmax = nums[i];
				index  = i;
			}
            else if (nums[i] > secmax) {
                secmax = nums[i];
            }
		}
		return secmax*2 <= firmax ? index:-1;
	}
};

/* the idea: no sort involved, just go through the nums once: recording
 * the max one, second max one, and the index of the max, keep updating it.
 * NOTICE: WE SHOULD ALSO UPDATE THE SECOND MAX ONCE WE FOUND THE MAX ONE, 
 * otherwsie the process is not complete!
 */
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		/* step 1 */
        int i = nums.size()-1;
		for (i; i >= 1; -- i) 
            if (nums[i] > nums[i-1])
                break;
        i --;
        /* case: when no next permutation possible */
		if (i < 0) {
			sort(nums.begin(), nums.end());
		    return;
		}
        /* step 2 */
        int nextGI = nums.size()-1;
        while (nums[i] >= nums[nextGI])
            nextGI --;
        /* step 3 */
        swap(nums[i], nums[nextGI]);
        
        /* step 4 */
        sort(nums.begin() + i + 1, nums.end());
        
	}
};


/* the idea: Math;
 * step_1: find the first non-acending number in reverse order, named it N
 * NOTICE: one N is at index 0, that means the array is ascending, only N at negative
 * index, meaning there is no next permutaiton!!
 * step_2: find the first number greater than N, named it M
 * step_3: switch N and M
 * step_4: reverse those number behind current position of M
 */
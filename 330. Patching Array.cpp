/*https://discuss.leetcode.com/topic/35494/solution-explanation/2*/
/* 
	let miss be the least # that cannot be form, we can form [1..miss) 
	if we have num < miss, we can form [1..miss + num)
	else we add miss to nums[], we can form form [1..miss + miss)

	repeat until miss > n then we are done
*/



class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
		long  miss = 1;
		int res = 0, index = 0;
		while (miss <= n) {
			if (index < nums.size() && nums[index] <= miss) {
				miss += nums[index];
				index ++;
			}
			else {
				miss += miss;
				res++;
			}

		}
		return res;        
    }
};


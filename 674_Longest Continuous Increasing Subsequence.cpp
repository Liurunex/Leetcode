class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (!nums.size()) return 0;
		int res = 1, curres = 1, index = 1;
		while (index < nums.size()) {
			if (nums[index-1] < nums[index])
				curres ++;
			else {
				res = max(res, curres);
				curres = 1;	
			}
			index ++;
		}
		return max(res, curres);
	}
};

/*
 * the trick is for the edge case, we count our last curres and
 * might not update res on this time, therefore we have to
 * update the res value before we return
 */

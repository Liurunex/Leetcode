class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.size() == 0)
    	    return 0;
    	int i = 0 , j = 0, maxl = 1, len = (int)nums.size();
    	int dp[len];

    	for (i = 0; i < len; i++) {
    	    dp[i] = 1;
    		for (j = 0; j < i; j++) {
    			if (nums[i] > nums[j]) {
    				dp[i] = max(dp[i], 1 + dp[j]);
    				maxl = max(maxl, dp[i]);
    			}
    		}
    	}

    	return maxl;
    }
};
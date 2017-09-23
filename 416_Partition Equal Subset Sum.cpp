class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto num:nums)
			sum += num;
		
        if (sum%2) return false;
        int target = sum/2;
        
		vector<vector<bool>> dp(nums.size()+1, vector<bool> (target+1, false));
		for (int i = 0; i < nums.size()+1; ++ i)
			dp[i][0] = true;
		
		for (int i = 1; i < nums.size()+1; ++ i) {
			for (int j = 1; j < target+1; ++ j) {
				if (j >= nums[i-1]) {
					dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
				}
			}
		}

		return dp[nums.size()][target];
	}
};
/* the trick: you cannot simpley use 1d dp here, since each number has limited 
 * times for picking up, change it to 2d dp will solve this question
 * another trick is your set the dp as size+1 in order to introduce the 0 case
 * but the index you used to access nums will change tp i-1, NOTICE
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp.back();
    }
};

/* O(1) space, 1d dp solution: here what we change is give the order to pick number and 
 * update the whole dp table, that is outer loop is to pick ith num, then update dp based
 * it, the reason how we avoid the mutiple pick same number is that we set the order and range
 * for each loop
 */

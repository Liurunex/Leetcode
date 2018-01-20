class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.size() < 2) return nums;
		sort(nums.begin(), nums.end());

		int target_len = 0, target_index = 0;
		vector<int> dp (nums.size(), 1);
		vector<int> pre (nums.size(), 0);
        
		for (int i = 1; i < nums.size(); ++ i) {
            pre[i] = i;
			for (int j = 0; j < i; ++ j) {
				if (!(nums[i]%nums[j]) && dp[j] >= dp[i]) {
					dp[i]  = dp[j]+1;
					pre[i] = j;
				}
			}
			if (target_len < dp[i]) {
				target_len   = dp[i];
				target_index = i;
			}
		}
		vector<int> res;
		while (target_len > 0) {
            target_len --;
			res.push_back(nums[target_index]);
			target_index = pre[target_index];
		}
		return res;
	}
};

/* the idea: DP + memorize position. The first thing we do is to sort 
 * the array since then we can only consider that nums[i] % nums[j] ?= 0 where i > j.
 * This is important as unsorted array we will have to consider both sides. Then we 
 * define our dp array: dp[i] means the maximum len of subset following the rules when
 * the last element is nums[i], then we can come up with the recurrent function:
 * dp[i] = max(dp[j]+1) where j belongs to [0, i-1], this is much similar to LIS dp problem
 * Since we need to print out the subset, we have another array to record the previous index of
 * number for current one, that is the key to print out the result! */
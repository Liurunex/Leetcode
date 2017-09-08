class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int i:nums)
			sum += i;
		if (sum < S || (sum+S) %2 == 1) return 0;
		sum += S;
		sum /= 2;
		
        sort(nums.begin(), nums.end());
		vector<int> dp (sum+1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); ++ i) {
			if (nums[i] > sum) break;
			for (int j = sum; j >= nums[i]; -- j)
				dp[j] += dp[j - nums[i]];
		}
		return dp[sum];
	}
};
    
/*
the great idea: convert the problem to a subset sum problem, that is, 
we say P is subset of all positive elements in nums, N is subset of all
negative elements (original all elements is positive); we want:
-> sum(P) - sum(N) = target 
-> sum(P)*2 = target + sum(P) + sum(N); since sum(P) + sum(N) = sum 
-> sum(P) = ( target + num) >> 1;

#1 Trick: if (sum == S) we cannot simply return 1, consider the case involved with 0
#2 Trick: we must check if (sum+target) is even otherwise the formula cannot work
#3 How many ways to select numbers from nums whose sum added up to target?
	this is a dp idea:
	go check if we decided to use each nums[i]
		go through target and dp table from trget to nums[i]: (candiate < nums[i]
		doesn't need to condiser), the purpose here is:
			update all dp[nums[i]+1..Target] based on dp[1..nums[i]-1]
			confirm the dp[nums[i]] based on dp[0];
 */
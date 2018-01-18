class Solution {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp (nums.size(), vector<int>(nums.size(), 0));

		for (int len = 1; len <= nums.size()-2; ++ len) {
			for (int left = 1; left <= nums.size()-1-len; ++ left) {
				int right = left + len - 1;
				for (int k = left; k <= right; ++ k) {
					dp[left][right] = max(dp[left][right], 
						nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
				}
			}
		}

		return dp[1][nums.size()-2];
	}
};

/* the idea: DP. We first define the dp problem, notice that we the value we get at by bursting
 * certain ballon is acquired by its adjacent values. Then we design the 2-dimension dp problem
 * the dp[i][j] defines the best value we cant get by bursting all ballons from i to j. So that
 * we can then write the recurrence function: dp[i][j] = max{nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]} 
 * where k is between [i,j].
 * Once we found the subproblem and recurrence fucntion, we then come to think about how to build the dp table:
 * first add 1 to head and tail of origin nums respectively. Then we use bottom up to build the table, that is 
 * go check the length of rang i~j from 1 to n, then conform the i and j, finally applied the 
 * recurrence function
 * */
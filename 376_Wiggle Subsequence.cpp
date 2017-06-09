class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
  		if (nums.size() == 0)
  		    return 0;
  		pair<int, int> p (1, 1);
  		vector<pair<int, int>> dp (nums.size(), p);
  		
  		int i = 0, j = 0, maxr = 1;
  		dp[0] = make_pair(1, 1);

  		for (i = 1; i < nums.size(); i++) {

			if (nums[i] > nums[i-1]) {
				dp[i].first = dp[i-1].second + 1;
				dp[i].second = dp[i-1].second;
			}
			else if (nums[i] < nums[i-1]) {
				dp[i].first = dp[i-1].first;
				dp[i].second = dp[i-1].first + 1;
			}
			else {
				dp[i].first = dp[i-1].first;
				dp[i].second = dp[i-1].second;
			}
			maxr = max(maxr, max(dp[i].first, dp[i].second));
  		}
  	
  		return maxr;
    }
};
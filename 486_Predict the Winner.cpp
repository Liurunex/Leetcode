class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
    	int i, j, n;
    	n = nums.size();
    	int sum[n];
    	sum[0] = nums[0];
    	vector<vector<int>> dp(n, vector<int>(n, 0));
		for (i = 0; i < nums.size(); i++) {
			dp[i][i] = nums[i];
			if (i >0) sum[i] = sum[i-1] + nums[i];
		}
    	
    	for (i = nums.size()-1; i >= 0; i--) {
    		for (j = i; j < nums.size(); j++) {
                if (i+1 == j) dp[i][j] = max(nums[i], nums[j]);
    			else if (i+1 < j) 
		  			dp[i][j] = max(nums[i] + sum[j] - sum[i] - dp[i+1][j], 
		  				nums[j] + sum[j-1] - sum[i] + nums[i] - dp[i][j-1]);
    		}
    	}
    	for (i = 0; i < nums.size(); i++) {
    		for (j = 0; j < nums.size(); j++) {
    		    cout << dp[i][j] << " ";
    		}
    	    cout << endl;
    	}
        return (dp[0][nums.size()-1] >= (sum[n-1]-dp[0][nums.size()-1]));
    }
};
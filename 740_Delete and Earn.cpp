class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (!nums.size()) return 0;

		map<int, int> frequntce;

		for (auto it:nums) {
			frequntce[it] ++;
		}

		vector<int> dp (frequntce.size(), 0);
		auto bg = frequntce.begin();
		dp[0] = frequntce.begin()->first * frequntce.begin()->second;
		bg ++;
        if (frequntce.begin()->first == bg->first-1)
		    dp[1] = max(dp[0], bg->first * bg->second);
       	else dp[1] = dp[0] + bg->first * bg->second;
       	int pre = bg->first;
		for (int i = 2; i < dp.size(); ++ i) {
			bg ++;
			int val = (bg->first * bg->second);
            //cout << pre << " <> " << bg->first << endl;
			if (pre == bg->first-1)
				dp[i] = max(dp[i-1], dp[i-2] + val);
			else dp[i] = dp[i-1] + val;
			pre = bg->first;
		}
		
		return dp.back();
	}
};

/* the idea: dp same as Hourse Robber + Map(num-frequency) to build the adjacent number list
 */
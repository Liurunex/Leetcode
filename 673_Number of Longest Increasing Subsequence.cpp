class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (!nums.size()) return 0;
		
		int res = 0, maxlen = 1;
		vector<int> dp_count (nums.size(), 1);
		vector<int> dp_length (nums.size(), 1);
		
		for (int i = 1; i < nums.size(); ++ i) {
			for (int j = 0; j < i; ++ j) {
				if (nums[j] < nums[i]) {
					if (dp_length[i] < dp_length[j]+1) {
						dp_length[i] = dp_length[j]+1;
						dp_count[i]  = dp_count[j]; 
					}
					else if (dp_length[i] == dp_length[j]+1)
						dp_count[i] += dp_count[j];
				}
			}
            maxlen = max(maxlen, dp_length[i]);
		}

		for (int i = 0; i < nums.size(); ++ i) {
			if (maxlen == dp_length[i])
				res += dp_count[i];
		}

		return res;
	}
};
/* the idea: normally we maintain a dp_len table to record the maximum len
 * LIS end up at nums[i]; however, we need more info for the sake of counting
 * # of LIS. On basis of that, we come up with another table dp_count to record
 * the numebr of current LIS end with nums[i];
 * the trick: it's easy to get the case dp_len[i] < dp_len[j]+1, where we just 
 * update dp_len[i] and dp_count[i], however another case might be omited:
 * dp_len[i] == dp_len[j]+1, which means we find a new LIS whose length is equl
 * to the LIS length ending at nums[i]. In that case, we must update dp_count[i] 
 */

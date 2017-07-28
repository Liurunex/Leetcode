/* TLE version */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0 || s <= 0) return 0;
	    int res = INT_MAX;
	    vector<int> sumArray (nums.size()+1, 0);
	    sumArray[1] = nums[0];
	    for (int i = 2; i < (int)sumArray.size(); ++ i)
		    sumArray[i] = sumArray[i-1] + nums[i-1];

	    for (int i = 0; i < (int)sumArray.size(); ++ i) {
		    for (int j = i; j < (int)sumArray.size(); ++ j) {
			    if ((sumArray[j] - sumArray[i]) >= s)
			    	res = min(j-i, res);
		    }
	    }
	    return res == INT_MAX ? 0 : res;
    }
};

/* two pointer version */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0 || s <= 0) return 0;
	    int res = INT_MAX;
	    vector<int> sum (nums.size()+1, 0);
	    sum[1] = nums[0];
	    for (int i = 2; i < (int)sum.size(); ++ i)
		    sum[i] = sum[i-1] + nums[i-1];
		int i = 0, j = 1;
		while (j < nums.size()+1) {	
			while (i < j && sum[j] - sum[i] >= s) {
				res = min(res, j-i);
				i ++;
			}
			j ++;
		}

		return res == INT_MAX ? 0 : res;
    }
};

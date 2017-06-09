class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty() || nums.size() < 4) return false;
        int i = 0, sum = 0;
        for (i = 0; i < nums.size(); i++) 
        	sum += nums[i];
        if (sum % 4 != 0) return false;
        const int len = sum/4;
        for (i = 0; i < nums.size(); i++) 
        	if (nums[i] > len) return false;

        sort(nums.rbegin(), nums.rend());
       	vector<int> allen(4, 0);
        return dfshelp(allen, 0, nums, len);
    }

    bool dfshelp(vector<int>& allen, int index, vector<int>& nums, const int len) {
    	if (allen[0] == len && allen[1] == len && allen[2] == len) return true;
    	if (index >= nums.size()) return false;

    	int i = 0;
    	for (i = 0; i < 4; i++) {
    		if (allen[i] + nums[index] <= len) {
    			allen[i] += nums[index];
    			if (dfshelp(allen, index+1, nums, len)) return true;
    			allen[i] -= nums[index];
    		}
    	}

    	return false;
    }
};

/* rbegin, rend*/
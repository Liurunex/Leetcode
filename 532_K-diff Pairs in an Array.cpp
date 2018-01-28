class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int res = 0, i = 0, j = 0;
		while (i < nums.size()) {
            j = i+1;
			int target = nums[i]+k;
            if (target > nums.back()) break;
			while (j < nums.size() && target > nums[j]) 
				++ j;
			if (j < nums.size() && target == nums[j])
                res ++;
            while (j < nums.size() && target == nums[j])
                ++ j;
            int pre = nums[i];
            while (i < nums.size() && pre == nums[i])
                ++ i;
		}
		return res;	
	}
};

/*the idea: Two Pointer. Notice we only need to count unique pair */
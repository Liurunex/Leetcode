class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> myset;
        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
        	if (j - i > k) {
        		myset.erase(nums[i]);
        		i ++;
        	}
    		auto target = myset.lower_bound((long)nums[j] - (long)t);
    		if (target != myset.end() && abs((long)*target - (long)nums[j]) <= (long)t) 
    			return true;
    		myset.insert(nums[j]);
        }
        return false;
    }
};

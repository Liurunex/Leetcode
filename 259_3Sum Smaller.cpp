class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++ i) {
            int lo = i+1, hi = nums.size()-1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] < target - nums[i]) {
                    res += hi - lo; // this means all cases where 3rd number = lo..hi satisfied 
                    lo ++;
                }
                else hi --;    
            }
            
        }
        return res;
    }
};

/* simialr to 3sum question */
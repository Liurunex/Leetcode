class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        int frontp = 1;
        int tailp = 1;
        int i = 0;
        
        for (i = 0; i < nums.size(); i++) {
            if (nums.size()-i-1>i) {
                output[i] = frontp;
                frontp = frontp * nums[i];
                output[nums.size()-i-1] = tailp;
                tailp = tailp * nums[nums.size()-i-1]; 
                continue;
            }
            output[i] *= frontp;
            frontp = frontp * nums[i];
            output[nums.size()-i-1] *= tailp;
            tailp = tailp * nums[nums.size()-i-1]; 
           
        }
        return output;
    }
};
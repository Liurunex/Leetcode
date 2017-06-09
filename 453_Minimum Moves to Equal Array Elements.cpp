class Solution {
public:
    int minMoves(vector<int>& nums) {
        int vmin = nums[0], res = 0;
    
        for (int i = 0; i < nums.size(); i++)
            vmin = min(nums[i], vmin);

        for (int i = 0; i < nums.size(); i++) {
                res += nums[i] - vmin;
        }

        return res;

    }
};
/* x^0 = x, x^x = 0 and think about that a^b^a = a^a^b */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++ i) 
            res ^= nums[i];
        return res;
    }
};

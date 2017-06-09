class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, n = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums.erase(nums.begin()+i);
                i --;
                n ++;
            }
        }
        while (n > 0) {
            nums.push_back(0);
            n --;
        }
    }
};
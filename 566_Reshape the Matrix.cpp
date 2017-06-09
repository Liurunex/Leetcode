class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) 
            for (int j = 0; j < nums[i].size(); j++) 
                sum += 1;
        if (sum != r*c) return nums;
        vector<vector<int>> res;
        vector<int> tem;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                tem.push_back(nums[i][j]);
                if (tem.size() == c) {
                    res.push_back(tem); 
                    tem.clear();
                }
            }
        }
        return res;
    }
};
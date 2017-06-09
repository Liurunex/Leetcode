class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cnums;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(),nums.end());
        permuteHelp(nums, cnums, visited, result);
        return result;
    }

    void permuteHelp(vector<int>& nums, vector<int>& cnums, vector<bool>& visited,vector<vector<int>> &result) {
        if (nums.size() == cnums.size()) 
            result.push_back(cnums);
        else {
            int i = 0;
            for (i = 0; i < nums.size(); i++) {
                if (visited[i] == false) {
                    if (i > 0 && !visited[i-1] && nums[i] == nums[i-1])
                        continue;
                    visited[i] = true;
                    cnums.push_back(nums[i]);
                    permuteHelp(nums, cnums, visited, result);
                    
                    visited[i] = false;
                    cnums.pop_back();
                }
            }
        }
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        vector<char> mark (nums.size(), 'h');
        int i = 0;
        for (i = 1; i < nums.size(); i++) 
            if (nums[i-1] + 1 == nums[i])
                mark[i] = 'b';

        i = 0;
        while (i < nums.size()) {
            if (mark[i] == 'h') 
                res.push_back(to_string(nums[i]));
            if (mark[i] == 'b') {
                if (i+1 == nums.size()){
                    res.back() += "->" + to_string(nums[i]);
                    break;
                }
                if (mark[i+1] == 'h')
                    res.back() += "->" + to_string(nums[i]);
            } 
            i++;
        }
        return res;
    }
};
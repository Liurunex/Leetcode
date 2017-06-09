/* 1 vector fine dp */
class Solution {
public:
    int rob(vector<int>& nums) {
    	if (nums.size() == 0) return 0;
        vector<int> table (nums.size(), 0);
        table[0] = nums[0];
        table[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i ++) 
        	table[i] = max(table[i-1], table[i-2] + nums[i]);
        
        return table[nums.size()-1];
    }
};

/* 2 vector slow dp */
class Solution {
public:
    int rob(vector<int>& nums) {
    	if (nums.size() == 0) return 0;
        vector<int> to_rob (nums.size(), 0);
        vector<int> no_rob (nums.size(), 0);
        to_rob[0] = nums[0];
        no_rob[0] = 0;
        for (int i = 1; i < nums.size(); i ++) {
        	to_rob[i] = no_rob[i-1] + nums[i];
        	no_rob[i] = max(to_rob[i-1], no_rob[i-1]);
        }
        return max(to_rob[nums.size()-1], no_rob[nums.size()-1]);
    }
};
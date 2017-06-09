class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++) {
            if (mymap.find(nums[i]) == mymap.end())
                mymap[nums[i]] = 1;
            else return true;
        }
        return false;
    }
};
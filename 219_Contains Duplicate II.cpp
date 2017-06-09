class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int, vector<int>> mymap;
        for (int i = 0; i < nums.size(); i++) {
            if (mymap.find(nums[i]) == mymap.end()) {
                vector<int> tem;
                tem.push_back(i);
                mymap[nums[i]] = tem;
            }
            else {
                for (int j = 0; j < mymap[nums[i]].size(); j++) 
                    if (abs(i - mymap[nums[i]].at(j)) <= k)
                        return true;
                
                mymap[nums[i]].push_back(i);
            }
        }
        return false; 
    }
};
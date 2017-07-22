class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dic;
        for (auto item1: nums1) 
        	dic[item1] = 0;
        
        vector<int> res;
        for (auto item2: nums2) 
        	if (dic.find(item2) != dic.end())
        		dic[item2] ++;
        
        for (auto it = dic.begin(); it != dic.end(); ++ it)
        	if (it->second)
        		res.push_back(it->first);

        return res;
    }
};
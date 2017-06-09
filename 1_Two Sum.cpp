class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	    unordered_map<int, int> mymap;
	    vector<int> res;
	    for (int i = 0; i < nums.size(); i ++) 
	    	mymap[nums[i]] = i;
     	for (auto it = mymap.begin(); it != mymap.end(); ++it )
            cout << " " << it->first << ":" << it->second;
	    for (int i = 0; i < nums.size(); i ++) {
	    	int tem = target - nums[i];
	    	if (mymap.find(tem) != mymap.end() && mymap.at(tem) != i) {
	    		res.push_back(i);
	    		res.push_back(mymap[tem]);
	    		return res;
	    	}
	    }
	    res.push_back(-1);
	    res.push_back(-1);
	    return res;
    }
};
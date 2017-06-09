class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> res;
    	vector<int> sub;
    	res.push_back(sub);
  
    	subsetHelp(res, 0, nums, sub);
    	return res;
    }

    void subsetHelp(vector<vector<int>>& res, int index, 
    	vector<int>& nums, vector<int>& sub) {
    	int i = 0;
    	for(i = index; i < nums.size(); i++) {
    		sub.push_back(nums[i]);
    		res.push_back(sub);
    		if (i + 1 < nums.size())
    			subsetHelp(res, i + 1, nums, sub);
    		sub.pop_back();
    	}
    }
};

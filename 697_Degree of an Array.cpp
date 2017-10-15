class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> dict;
		for (int i = 0; i < nums.size(); ++ i)
			dict[nums[i]] ++;
		int freq = -1;
		vector<int> modes;
		for (auto i  = dict.begin(); i != dict.end(); ++ i) {
			if (i->second == freq) 
				modes.push_back(i->first);
			else if (i->second > freq) {
				modes.clear();
				freq = i->second;
				modes.push_back(i->first);
			}
		}
		if (freq == 1) return 1;
		
		int res = INT_MAX;
		for (int mode:modes) {
			int start = -1, end = -1;
			for (int i = 0; i < nums.size(); ++ i) {
				if (nums[i] == mode) {
					start = i;
					break;
				}
			}

			for (int i = nums.size()-1; i >= 0; -- i) {
				if (nums[i] == mode) {
					end = i;
					break;
				}
			}
			res = min(res, end-start+1);
		}
		
		return res;
	}
};
/* the idea: we first find all modes, then for each mode, we iterate from
 * left and right respectively, update the min value
 * /

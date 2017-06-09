class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> res;
		if (nums.size() == 0) {
			res.push_back(upper > lower ? to_string(lower) + "->" + to_string(upper) : to_string(lower));
			return res;
		}
		string srange = "";
		long int llower = (long)lower, uupper = (long)upper;
		for (int i = 0; i < nums.size(); ++ i) {
			if (nums[i] > uupper) break;
			if (nums[i] < llower) continue;
			if (nums[i] != llower){
				srange = llower + 1 == (long)nums[i] ? to_string(llower) : to_string(llower) + "->" + to_string((long)nums[i]-1);
				res.push_back(srange);
				srange.clear();
			}
			llower = (long)nums[i] + 1;
		}

		if (llower <= uupper) {
			srange = llower == uupper ? to_string(llower) : to_string(llower) + "->" + to_string(uupper);
			res.push_back(srange);
			srange.clear();
		}
		return res;
	}
};

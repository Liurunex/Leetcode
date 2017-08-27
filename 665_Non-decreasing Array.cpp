class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() < 2) return 1;

		int count = 0;
		for (size_t i = 1; i < nums.size(); ++ i) {
			if (nums[i-1] > nums[i]) {
				count ++;
				if (count > 1) return 0;
				if (i-2 >=0 && nums[i-2] > nums[i]) nums[i] = nums[i-1];
				else nums[i-1] = nums[i];
			}
		}
		return 1;
	}
};

/* once the unvalid case nums[i-1] > nums[i] happened, we should consider two cases:
	the one is nums[i] is in the range of [nums[i-2], nums[i-1]), this case we have to convert 
	nums[i-1] to nums[i] for greedy concern, the other case is where nums[i] is less than nums[i-2],
	then we have no choice but convert nums[i] to nums[i-1]
*/
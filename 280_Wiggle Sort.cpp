class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() < 2) return;
		for (size_t i = 1; i < nums.size(); ++ i) {
			if ((!(i%2) && nums[i] > nums[i-1]) || ((i%2) && nums[i] < nums[i-1])) {
				int tem   = nums[i];
				nums[i]   = nums[i-1];
				nums[i-1] = tem; 
			}
		}
	}
};
/*
0 1 2 3 4 ... 
i = 2k:  2 4 ...
nums[i-1] >= nums[i]
i = 2k+1 1 3 ...
nums[i-1] <= nums[i]

for i = 2k:
nums[i-1] >= nums[i] <= nums[i+1] => nums[i+2] <= nms[i+3]
 */
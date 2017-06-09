class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		int i = 0;
		for (i = nums.size()-1; i >= 0; -- i)
			if (i > 0)
			    if (nums[i] > nums[i-1])
				    break;
        cout << i << endl;
		if (i <= 0) {
			sort(nums.begin(), nums.end());
		    return;
		}
		else {
			int minIndex = nums.size()-1;
			while (nums[i-1] >= nums[minIndex])
				minIndex -= 1;
			swap(nums[i-1], nums[minIndex]);
			sort(nums.begin() + i, nums.end());
		}
	}
};

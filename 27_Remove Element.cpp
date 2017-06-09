class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0) return 0;
		int i = 0, count = 0;
		for (int i = 0; i < nums.size(); i ++) {
			if (val == nums[i])
				continue;
			count ++;
		}
		cout << nums.size() << endl;
		return count;
	}
};

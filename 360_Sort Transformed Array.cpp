class Solution {
public:
	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		if (!nums.size()) return {};
		vector<int> res (nums.size(), 0);		
		int left = 0, right = nums.size()-1;
		int pospostive = a > 0 ? nums.size()-1: 0;
		while (left <= right) {
			int sumleft  = a*nums[left]*nums[left] + b*nums[left] + c;
			int sumright = a*nums[right]*nums[right] + b*nums[right] + c;
			if (a > 0) {
				int isleft  = sumright > sumleft ? 0:1;
				int value   = sumright > sumleft ? sumright:sumleft;
				res[pospostive] = value;
				pospostive --;
				if (isleft) left ++;
				else right --;
			}
			else {
				int isleft  = sumright > sumleft ? 1:0;
				int value   = sumright > sumleft ? sumleft:sumright;
				res[pospostive] = value;
				pospostive ++;
				if (isleft) left ++;
				else right --;
			}
		}
		return res;
	}
};

/* classic two pointer method */
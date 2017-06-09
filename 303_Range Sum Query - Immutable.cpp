class NumArray {
private: vector<int> tnums;
public:
    NumArray(vector<int> nums) {
    	if (nums.size() == 0) return;
    	tnums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
        	tnums.push_back(0);
        	tnums[i] += nums[i] + tnums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        if (i > 0)
            return tnums[j] - tnums[i-1];
        return tnums[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
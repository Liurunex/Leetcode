class NumArray {
private:
	vector<int> bitree;
	vector<int> origin;
public:
	NumArray(vector<int> nums) {
		origin.resize(nums.size(), 0);
		bitree = vector<int> (nums.size()+1, 0);
		for (int i = 0; i < nums.size(); ++ i)
			update(i, nums[i]);
	}

	void update(int i, int val) {
		int diff = val - origin[i];
		origin[i] = val;
		int index = i + 1;
		while (index < bitree.size()) {
			bitree[index] += diff;
			index += index & (-index);
		}
	}

	int sumRange(int i, int j) {
		int sum = 0;
		int index = j+1;
		while (index > 0) {
			sum += bitree[index];
			index -= index & (-index);
		}
		index = i;
		while (index > 0) {
			sum -= bitree[index];
			index -= index & (-index);
		}
		return sum;
	}
};

/* the idea: Binary Index Tree;
 * Notice that the update function accept the change-to value, not differnece
 * check Binary Index Tree: http://blog.csdn.net/int64Ago/article/details/7429868
 */
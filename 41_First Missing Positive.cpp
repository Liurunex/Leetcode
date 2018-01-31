class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int i = 0, n = nums.size();
		while (i < n) {
			if (nums[i] < 1 || nums[i] > n || nums[i] == i+1 || nums[i] == nums[nums[i]-1]) {
				++ i;
				continue;
			}
            //swap(nums[i], nums[nums[i]-1]);
			int tem = nums[i];
			nums[i] = nums[tem-1]; 
			nums[tem-1] = tem;//CANNOT use nums[nums[i]-1] here as it has changed
		}
		for (int i = 0; i < n; ++ i)
			if (nums[i] != i+1) return i+1;
		return n+1;
	}
};
/* the idea: Hash-table thought. 把array自己当成hash-table用，利用index来构建映射，就是
 * 尽量使得nums[i] = i+1, 完成以上处理，即可通过iterate 第一个nums[i] != i+1的地方来返回第一个
 * miss positive i+1. 处理过程：
 * 如果 nums[i] == i+1 或者 nums[i]不在[1,n]，跳过，因为如果nums[i] > n，那 miss passive必然在[1,n]；
 * 否则我们要swap nums[i] and nums[nums[i]-1]，因为nums[i]的值应该处于nums[i]-1的位置！
 * 注意当nums[i] == nums[nums[i]-1]的时候，会导致死循环，只能跳过！
 * */
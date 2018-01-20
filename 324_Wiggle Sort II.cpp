class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> tem = nums;
		sort(tem.begin(), tem.end());

		int pre = (nums.size()+1)/2-1, post = nums.size()-1;

		for (int i = 0; i < nums.size(); ++ i) {
			nums[i] = i&1 ? tem[post--]:tem[pre--];
		}
	}
};

/* the idea: Sort + Divide. We first sort the array. Then we divide the
 * sorted array intp left and right part divided by the median, then lets
 * start from the end of the two parts, pick the left.back() to the even position,
 * as well as pick the right.back() to the odd position, keep moving our two back 
 * pointers until we go through the whole array. In this way, we can assure that:
 * a[even] < a[odd] > a[even] ... since the left part vlaue always less than right
 * part. NOTICE we cannot pick from the start of left and right, see the prove:
 * https://discuss.leetcode.com/topic/32861/3-lines-python-with-explanation-proof 
 * */


class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		/* quick sort idea */
		auto it = nums.begin() + nums.size()/2;
		nth_element(nums.begin(), it, nums.end());
		int median = *it;

		/* three way partitioning */

		int i = 0, j = 0, n = nums.size(), k = nums.size()-1;

		auto A = [&](int index) -> int {
			return (1+2*index)%(n|1);
		}; 

		while (j <= k) {
			if (nums[A(j)] > median)
				swap(nums[A(i ++)], nums[A(j ++)]);
			else if (nums[A(j)] < median)
				swap(nums[A(j)], nums[A(k --)]);
			else j ++;
		}
	}
};
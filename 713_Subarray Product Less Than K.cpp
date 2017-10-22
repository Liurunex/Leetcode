class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int res = 0, left = 0, right = 0;
		long cur_product = nums[left];
		while (right < nums.size()) {
			if (cur_product < k) {
				res += right-left+1;
				right ++;
				cur_product *= nums[right];
			}
			else {
				while (cur_product >= k && left <= right) {
					cur_product /= nums[left];
					left ++;
				}
				if (cur_product >= k) {
					cur_product = nums[left];
					left ++;
					right ++;
				}
			}
		}
		return res;
	}
};
/* the idea: sliding window, once we meet question about contiguous array
 * we should consider the sliding window; the method here is we keep moving
 * the right window edge until and increasing the valid subarray number
 * until we find the product is invalid; then we keep moving the left
 * edge until the product is valid, or if we cannot make it happen until
 * the left == right, that means the number at right edge has excess the
 * target product, which means we must adjust both left and right window
 * edges to the next index to keep the process going until the right edge
 * reach the boundary
 */

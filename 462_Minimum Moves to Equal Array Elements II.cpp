class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int res = 0, mid = nums.size()/2;
		nth_element(nums.begin(), nums.begin()+mid, nums.end());
		for (int itm:nums) {
			res += abs(itm-nums[mid]);
		}
		return res;
	}
};
/* the idea: try to use nth_element to find the median value in
 * O(n), the key point is to understand the nth_element: it is 
 * similar to quick sort, both of them use the partition thoughts
 * where pick the pivot, swap it with the last element in array, then
 * traveal the array to by using two pointers(one for sortIndex, one
 * for traveal index) for the sake of comparing with pivot to locate 
 * the pivot sorted the position, repeat this process until we have 
 * only 3 elements in our partition, then do a normal sort will be good;
 * NOTICE: the pivot select method was 3-point way: pick the median 
 * value as pivot from the unsorted array positions[begin, median, end]]
 */

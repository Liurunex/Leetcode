class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int hight = nums.back() - nums[0];
		int low = INT_MAX;
		for (int i = 0; i < nums.size()-1; ++ i)
			low = min(low, nums[i+1]-nums[i]);
		while (low <= hight) {
			int mid = low + (hight-low)/2;
            cout << mid << endl;
			int i = 0, j = 1, count = 0;
            //O(n) cost for serach paris count
			while (i < nums.size()-1) {
				while (j < nums.size() && nums[j]-nums[i] <= mid)
					++ j;
				count += j-i-1; // -1 since j current not satisfy nums[j]-nums[i] <= mid
				i ++;
			}
			if (count < k)
			    low = mid+1;
			else hight = mid-1;
		}
		return low;
	}
};
/* the idea: Binary Search + 尺取法two pointer. 给nums排序，然后算出max和min的pair distance，
 * 接着用 binary search，search的范围就是[min_dist, max_dist]，在BS中，每一次算出mid，然后count
 * 所有不大于mid距离的pair的counter，这里用的尺取法，其实就是sliding window + sorted array，可在
 * O(n)算出counter；之后就是binary search条件判断，这里用的lower_bound的思路：只有当count < k是取右边区间，
 * 其余取左边，这里在发现count == k时候不能返回，因为此时mid不一定真的存在于pair distance中，所以得用
 * BS不断迫近！
 * */

// TLE
class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		multiset<int> distance;
		for (int i = 0; i < nums.size(); ++ i) {
			for (int j = i+1; j < nums.size(); ++ j) {
				distance.insert(abs(nums[i]-nums[j]));
			}
		}
        multiset<int>::iterator itr = distance.begin();
        for (int i = 0; i < k-1; ++ i)
            itr ++;
		return *itr;
	}
};
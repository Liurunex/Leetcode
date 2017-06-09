/* solution 1 based on temporary vector */
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> res;
		int i = 0, j = 0;
		while (i < m && j < n) {
			if (nums1[i] <= nums2[j])
				res.push_back(nums1[i++]);
			else
				res.push_back(nums2[j++]);
		}
		for (;i < m; ++ i)
			res.push_back(nums1[i]);
		for (;j < n; ++ j)
			res.push_back(nums2[j]);
		for (int i = 0; i < (m+n); ++ i)
			nums1[i] = res[i];
	}
};
/* solution 2 start from the end of new sorted arrary part int nums1 */
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m-1, j = n-1, cur = m+n-1;
		while (j >= 0) {
		    if (i >= 0)
		        nums1[cur--] = nums1[i] > nums2[j] ? nums1[i--]:nums2[j--];
	        else
	            nums1[cur--] = nums2[j--];
		}
	}
};

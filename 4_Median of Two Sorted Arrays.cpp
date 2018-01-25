class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		int mid = (m+n)/2;
		if ((m+n)%2 != 0)
            return findKth(nums1, nums2, 0, 0, mid+1);
		else
			return (findKth(nums1, nums2, 0, 0, mid) + findKth(nums1, nums2, 0, 0, mid+1))/2.0;
	}

	int findKth(vector<int>& nums1, vector<int>& nums2, int s1, int s2, int k) {
		int m = nums1.size()-s1, n = nums2.size()-s2;
		if (m > n)
			return findKth(nums2, nums1, s2, s1, k);
		if (nums1.size()-s1 == 0) return nums2[s2+k-1];
		if (k == 1) return min(nums1[s1], nums2[s2]);
        
        int restS1 = nums1.size()-s1;
		int hK1 = min(k/2, restS1);
		int hK2 = k - hK1;
		int value_hk1 = nums1[s1+hK1-1];
		int value_hk2 = nums2[s2+hK2-1];

		if (value_hk1 < value_hk2) {
			return findKth(nums1, nums2, s1+hK1, s2, k - hK1);
		}
		else if (value_hk1 > value_hk2) {
			return findKth(nums1, nums2,  s1, s2+hK2, k - hK2);
		}
		else {
			return value_hk1;
		}

	}
};

/* the idea: Divide and Concuqer + Binary Search。We generalize this problem to find Kth
 * smallest value in the array, where k is the median index. Therefore we get two cases to
 * consider: total size even or odd. The key is to implement find Kth smallest function. 
 * The thought is: since two arrays are sorted, we take the k/w number from both of them, 
 * then comparing thier size: say A[k/2-1] and B[k/2-1]:
 * if A[k/2-1] < B[k/2-1], it means we don't need to care about A[0..k/2-1], since we know that
 * in this case A[k.2-1] is at most larger than k/2-1 + k/2-1  -> k-2 number, where we don't need it
 * anymore, therefore we drop A[0..k/2-1] to continue the search in recursive way, NOTICE to change k's
 * value, array A's searching range at this point. The caseA[k/2-1] > B[k/2-1] is vice verse.
 * The terminal case is: 
 * if one array become empty, return the kth value from another;
 * if k == 1, return the min value between head of two arrays;
 * if A[k/2-1] == B[k/2-1] return that value since it is on k the postion after merging.
 * Trick 1: k is keep changing in each recusive call;
 * Trick 2: We first confrim the small and larger array by comapring two arrays' size, the reason is
 * in later case one array has no more than k/2 values, where we have to detect and view the last value
 * as the 'k/2' value
 * Trick 3: Everytime we drop k/2 values, time complecity O(logmn) == O(log(m+n))
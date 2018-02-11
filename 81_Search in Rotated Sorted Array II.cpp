class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) return true;
            
            if (nums[mid] > nums[right]) {
                if (target > nums[mid]) left = mid+1;
                else {
                    if (target > nums[right]) right = mid-1;
                    else left = mid+1;
                }
            }
            else if (nums[mid] < nums[right]){
                if (target < nums[mid]) right = mid-1;
                else {
                    if (target > nums[right]) right = mid-1;
                    else left = mid+1;
                }
            }
            else {
                right --;
            }
        }
        return false;
    }
};

/*
当有重复数字，会存在A[mid] = A[end]的情况。此时右半序列A[mid-1 : end]可能是sorted，也可能并没有sorted，如下例子。

3 1 2 3 3 3 3 
3 3 3 3 1 2 3

所以当A[mid] = A[end] != target时，无法排除一半的序列，而只能排除掉A[end]：
A[mid] = A[end] != target时：搜寻A[start : end-1]
正因为这个变化，在最坏情况下，算法的复杂度退化成了O(n)：
*/
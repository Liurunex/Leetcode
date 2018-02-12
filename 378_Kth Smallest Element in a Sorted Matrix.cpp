class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left <= right) {
            int mid = left + (right - left)/2;
            int count = 0;
            for (int i = 0; i < matrix.size(); ++ i)
                count += helper(matrix[i], mid);
            //if (count == k) return mid;
            if (count < k) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
    
    int helper(vector<int>& nums, int& val) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] <= val) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};
// 1.每一行做BS:
// 对值做binary search，不断趋近，算出mid，对每一行取upper_bound找比mid大的第一个元素，
// 更新counter，NOTICE算出总的counter后要用lower_bound，因为mid不一定在matrix中，不能
// k == counter 就返回了。
// 
// 2. 利用行列都是sorted，和1区别于计算count的方式，我们从左下角开始计算count，利用search in 2D
// matrix 方法，
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left <= right) {
            int mid = left + (right - left)/2;
            int count = 0;
            count += helper(matrix, mid);
            //if (count == k) return mid;
            if (count < k) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
    
    int helper(vector<vector<int>>& matrix, int& val) {
        int i = matrix.size()-1, j = 0, count = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (val > matrix[i][j]) {
                count += i+1;
                j ++;
            }
            else if (val < matrix[i][j]) {
                i --;
            }
            else {
                count += i+1;
                j ++;
            }
        }
        return count;
    }
};


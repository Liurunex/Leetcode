/* 2 dp tables recording 2 arry [0..n-1] & [1..n]*/
class Solution {
public:
    int rob(vector<int>& nums) {
    	if (nums.size() == 0) return 0;
    	if (nums.size() == 1) return nums[0];
    	if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> norob1 (nums.size(), 0);
        vector<int> mayrob1 (nums.size(), 0);
        
        norob1[1] = nums[1];
        norob1[2] = max(nums[1], nums[2]);
        
        mayrob1[0] = nums[0];
        mayrob1[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i ++) {
        	if (i > 2)
    			norob1[i] = max(norob1[i-1], norob1[i-2] + nums[i]);
        	if (i < nums.size()-1)
        		mayrob1[i] = max(mayrob1[i-1], mayrob1[i-2] + nums[i]);
        }
        
        return max(norob1[nums.size()-1], mayrob1[nums.size()-2]);
    }
};
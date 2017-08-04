class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, right = nums.size()-1, cur = 0;
		while (cur <= right) {
			if (nums[cur] == 0) {
				int tem    = nums[cur];
				nums[cur]  = nums[left];
				nums[left] = tem;
				cur  ++;
				left ++;
				continue;
			}
			if (nums[cur] == 2) {
				int tem = nums[cur];
				nums[cur] = nums[right];
				nums[right] = tem;
				right --;
				continue;
			}
			if (nums[cur] == 1)
				cur ++;
		}
	}
};

/*  it's actually a thriple-pointer method, the way is: left is the boundary of 0/1, 
	right is the boundary of 1/2, that is you keep exchange with left and right with your
	current pointer, NOTICE the while loop end condition must be <=, since you shoudl check
	the last unchecked element which is at the current right position, take a look here: 
	http://bangbingsyb.blogspot.com/2014/11/leetcode-sort-colors.html
*/
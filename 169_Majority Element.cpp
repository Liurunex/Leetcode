class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	if (nums.size() == 1) return nums[0];
        int count = 1, major = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
        	if (!count) {
				count = 1;
				major = nums[i];
			}
			else if (major == nums[i])
				count ++;
			else count --;
        }
    	return major;
    }
};

/* the solution is Boyer_Moore Voting Algorithm, check on Wiki
there is a bit solution: see dicusssion 6 suggested solution in c++ 
*/

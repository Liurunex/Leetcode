class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	if (nums.size() < 3) return false;
    	stack<int> jStack;
    	int kcandicate = INT_MIN; /* must be min int*/
        for (int i = nums.size()-1; i >= 0; i --) {
        	if (nums[i] < kcandicate) {
        		if (!jStack.empty()) return true;
        		continue;
        	}
        	/* maintain the status nums[j] > nums[k] > nums[i]*/
        	while (!jStack.empty() && nums[i] > jStack.top()) {
        		kcandicate = jStack.top();
        		jStack.pop();
        	}
        	if (nums[i] > kcandicate)
        		jStack.push(nums[i]);
        }
        return false;
    }
};
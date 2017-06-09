class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        int current_index = 0;
        while (current_index < nums.size()-1 && current_index <= max_reach) {
        	max_reach = max(nums.at(current_index) + current_index, max_reach);
        	current_index ++;
        }
        if (max_reach >= (nums.size()-1))
        	return true;
        else 
	        return false;
    }
};

/* TLE Solution:
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>::iterator test = nums.begin();
        int max = *test;
        int i = 0;
        
        if (nums.size() == 1)
            return true;

        while (i < max) {
                i ++;
                test ++;
                if (test == nums.end()-1)
                    return true;
                if (*test == 0 || *test <= (max-i)) 
                    continue;
                vector<int> next;
                for(vector<int>::iterator it=test; it!=nums.end(); it++)
                    next.push_back(*it);
                if (canJump(next))
                    return true;
        }
        
        return false;
    }
};
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, zeroCount = 0, k = 1, left = 0;
        queue<int> zeroPos;
        for (int i = 0 ; i < nums.size(); ++ i) {
            if (!nums[i]) zeroPos.push(i);
            while (zeroPos.size() > k) {
                left = zeroPos.front() + 1;
                zeroPos.pop();
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};
/* the idea: Sliding Window (Queue way) + k flip generazation. The follow up requires not
 * to access any previous number as it is infinite array. We use queue
 * to implement the sliding window: queue stores all 0's position up to
 * current right position. Once we find the queue size has excess the limitation
 * of k zeros, we pop from queue, assign (val+1) to our left pointer, NOTICE the value assigned
 * to left must plus one since left is the start, and the window now has already k zeros! */

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, pre = 0, count = 0;
        for (int i:nums) {
            count ++;
            if (!i) {
                pre = count;
                count = 0;
            }
            res = max(res, pre+count);
        }
        return res;
	}
};

/* the idea: String. We need a counter to count how many consecutive
 * ones we have currently, and a pre_counter to store the previous
 * consecutive ones number. Since we have one time change to change 
 * one zero to one, then we change the process: WE UPDATE res when
 * meet with 1, but reset the counter when meet with 0. Why: since we
 * have one change to flip a 0, thus we have to increase counter even
 * meet with 0. Meanwhile, we should update the res when meet with 1
 * so that we don't need to deal with the ending with 1 case */
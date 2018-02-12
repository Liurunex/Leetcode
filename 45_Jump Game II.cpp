class Solution {
public:
    int jump(vector<int>& nums) {
        int curMax = 0, preMax = 0, index = 0, res = 0;
        vector<int> path (nums.size(), -1);
        while (curMax < nums.size()-1) {
            preMax = curMax;
            while (index <= preMax) {
                if (curMax < index+nums[index]) {
                    curMax = index+nums[index];
                    path[res] = index;
                }
                index ++;
            }
            res ++;
            if (preMax == curMax) return -1;
        }
        path.push_back(nums.size()-1);
        for (int i:path) {
            if (i != -1)
                cout << i << " ";
        }
        cout << endl;
        return res;
    }
};
// 打印路径，就是在更新curmax时候更新path 中的index
class Solution {
public:
	int jump(vector<int>& nums) {
		int curMax = 0, res = 0, index = 0;
		while (curMax < nums.size()-1) {
			int preMax = curMax;
			for (; index <= preMax; index ++) {
				curMax = max(curMax, index + nums[index]);
			}
			res ++;
			if (preMax == curMax) return -1;
		}
		return res;
	}
};
/* the idea: Greedy. 一般的dp过不来了，考虑greedy，记录curMax，res, index为起始：
 * 不断的更新curMax直到 curMax >= nums.size()-1. 更新过程：记下preMax，然后遍历从
 * 当前index到preMax，即是此前jump能reach到的所有点，然后update curMax, 遍历完后，res++因为
 * 我们相当于只作了一次跳跃，然后判断下curMax > preMax，否则我们已经掉入0，不能再前进
 * */

/* dp will time out */
class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> dp (nums.size(), INT_MAX);
		dp[0] = 0;
		for (int i = 1; i < nums.size(); ++ i) {
			for (int j = 0; j < i; ++ j) {
				if (nums[j] + j >= i)
					dp[i] = min(dp[j]+1, dp[i]);
			}
		}
		return dp[nums.size()-1];
	}
};

class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> dp (nums.size(), INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < nums.size(); ++ i) {
			for (int j = 1; j <= nums[i]; ++ j) {
                if (i+j < nums.size())
                    dp[i+j] = min(dp[i]+1, dp[i+j]);
			}
		}
		return dp[nums.size()-1];
	}
};
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		stack<int> helpstack;
		unordered_map<int, int> mimumstore;
		for(int i = 0; i < nums.size(); ++ i) {
			mimumstore[nums[i]] = -1;
			if (helpstack.empty() || helpstack.top() >= nums[i]) {
				helpstack.push(nums[i]);
				continue;
			}
			while (!helpstack.empty() && helpstack.top() < nums[i]) {
				mimumstore[helpstack.top()] = i;
				helpstack.pop();
			}
			helpstack.push(nums[i]);
		}
		for (int i = 0; i < findNums.size(); ++ i) {
			if (mimumstore[findNums[i]] == -1)
				findNums[i] = -1;
			else findNums[i] = nums[mimumstore[findNums[i]]];
		}
		return findNums;
	}
};

/*
the idea is keep updating the stack to maintain the descending elements
 */
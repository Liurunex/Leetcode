class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		vector<double> newnum (nums.begin(), nums.end());
		vector<char> opeartions {'+', '-', '_', '*', '/', '|'};
		return dfshelper(newnum, opeartions);
	}

	bool dfshelper(vector<double>& nums, vector<char>& opeartions) {
		if (nums.size() == 1) {
			return abs(nums[0] - 24.0) < 0.0001;
		}
		for (int i = 0; i < nums.size(); ++ i) {
			for (int j = i+1; j < nums.size(); ++ j) {
				double tem = 0.0;
				for (char op:opeartions) {
					if ((!nums[j] && op == '/') || (!nums[i] && op == '|'))
						continue;
					switch(op) {
						case '+': tem = nums[i]+nums[j]; break;
						case '-': tem = nums[i]-nums[j]; break;
						case '_': tem = nums[j]-nums[i]; break;
						case '*': tem = nums[i]*nums[j]; break;
						case '/': tem = nums[i]/nums[j]; break;
						case '|': tem = nums[j]/nums[i]; break;
					}
					
					double cur = nums[i];
					double nex = nums[j];
					nums[j] = tem;
					nums.erase(nums.begin()+i);
					if (dfshelper (nums, opeartions))
						return true;
					nums.insert(nums.begin()+i, cur);
					nums[j] = nex;

				}
			}
		}
		return false;
	}
};
/* the idea: DFS Backtracking. The basic thought is we pick two number, do a calculation,
 * replace the two number with the result, then repeate the process until there is only one
 * number, which is the final result after a series of opeartion, if it equaled to 24, we're done,
 * otherwise we applied backtracking process which is replace the result number with orginal two
 * number in vector at the original position.
 * Trick 1: When we comparing the only number with 24, we should use epsilion comparing, since the
 * dividing between number will lose precesion, like 8/3 is infinte which will round to 2.6 so that
 * affect our final results not accurately equal to 24!
 * Trick 2: Choose two number twice is not wise since we get the same result of operation +, *, so 
 * that we add two operations to complete the divide and minus opeartion like a/b, b/a, a-b, b-a. */
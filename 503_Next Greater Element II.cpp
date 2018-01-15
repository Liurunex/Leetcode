class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		if (!nums.size()) return {};
		stack<pair<int, int>> mystack;
		vector<int> res (nums.size(), -1);
		int pre = nums[0];
		mystack.push({nums[0], 0});
		
		int n = nums.size();
		for (int i = 1; i < n*2; ++ i) {
			if (nums[i%n] > pre) {
				while (!mystack.empty() && mystack.top().first < nums[i%n]) {
					if (res[mystack.top().second] == -1)
						res[mystack.top().second] = nums[i%n];
					mystack.pop();
				}
			}

			pre = nums[i%n];
			mystack.push({nums[i%n], i%n});
		}

		return res;
	}
};

/* the idea: Stack; We use stack to store those numbers who has not assigned with
 * the greater value. In this case, we keep iterating the vector, NOTICE WE MUST
 * travel the vector twice SINCE it's CIRCULAR ARRAY, otherwise we cannot handle case
 * like [5, 4, 3, 2, 1]. By traveling, we need a pre to record the previous visited number,
 * (or we can just use the top() of stack). Each time we find current visiting number is greater
 * than the pre (or top()), that means we can assign the top() value with its next greater number,
 * so that update the res vector and pop the current top() since we have done with it (NOTICE we 
 * can also take a look if the next great value has been set)
*/
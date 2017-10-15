class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		if (nums.size() < k) return false;
		if (!k || k == 1 || !nums.size()) return true;
		int sum = 0;
		for (int num:nums)
			sum += num;
		if (sum%k != 0) return false;

		int target = sum/k;
		vector<int> subSum (k, 0);
		vector<int> visited (nums.size(), 0);

		return dfshelper(nums, visited, subSum, target, k, 0, 0);

	}

	bool dfshelper(vector<int>& nums, vector<int>& visited,
		vector<int>& subSum, int target, int k, int setIndex, int start) {

		if (subSum[setIndex] == target) {
			if (setIndex == k-2) return true;
			return dfshelper(nums, visited, subSum, target, k, setIndex+1, 0);
		}
		for (int i = start; i < nums.size(); ++ i) {
			if ( visited[i] || subSum[setIndex] + nums[i] > target)
				continue;
			visited[i] = 1;
			subSum[setIndex] += nums[i];
			if (dfshelper(nums, visited, subSum, target, k, setIndex, i+1))
				return true;
			visited[i] = 0;
			subSum[setIndex] -= nums[i];			
		}
		return false;
	}
};

/* the idea: dp will not work, here I use bracktracking dfs, that is we need a visited
 * map to see if the number has been used in previous subset, and a vector subSum to
 * record the sum of the k subset respectively; we do the dfs recusive call, once the
 * current subSum[i] is equal to target and i == k-2, which means we have found 3 subsets
 * whose sums to target and we are done, otherwise keep recursvively calling the fucntion to 
 * check the next subset;
 * in other case where subSum[i] != target, we go through the num, using backtracking throghts
 * to add a number into current subset, change the visit map, and then call the resursive fucntion, 
 * notice here we set a start limit to avoid using same element; finally we check if the recursive fucntion
 * return true, if so we have done, otherwise we shoul pop out the previous added number and reset the
 * visted map to previosut status, then iterater to next candaites numebr adding to the current subset
 */

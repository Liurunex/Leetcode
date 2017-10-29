class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int, int> dict;
		for (int it:nums)
			dict[it] ++;
		int res = 0;
		for (int it : nums) {
			if (dict.count(it-1))
				res = max(res, dict[it]+dict[it-1]);
		}
		return res;
	}
};
/*the idea: idea 1 is using hashmap record all number and its coutners, once
 * we find key-1 existed, then update results, double loop
 */

/* the idea: sort the array and updat the res in one loop
 */
class Solution {
public:
	int findLHS(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 1, start = 0; i < nums.size(); ++ i) {
			int diff = nums[i] - nums[start];
			if (diff > 1) {
                while (nums[start] == nums[++start]);
            }
			else if (diff == 1) 
				res = max(res, i-start+1);
		}

		return res;
	}
};

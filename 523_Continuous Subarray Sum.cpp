class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		for (int i = 0; i < nums.size(); ++ i) {
			int sum = nums[i];
			for(int j = i+1; j < nums.size(); ++ j) {
				sum += nums[j];
				if (sum == 0 && k == 0) return true;
				if(k != 0 && sum % k == 0) return 1;
			}
		}
		
		return 0;
	}
};

/*
the idea: cumltimative sum method, but run slowly

the smart idea: notice for a and b, if a % k == b % k = c
then (a-b) % k = 0; knowing that, we count sum of at each 
index from (0..i), and compute its remainder divided by k;
store these in hash_map, once we find two same key, we are done,
notice the cornor cases
 */

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int sum = 0;
		unordered_map<int, int>remainder;
		remainder[0] = -1;
		for (int i = 0; i < nums.size(); ++ i) {
			sum += nums[i];
			int target = k == 0 ? sum :(sum%k);
			if (remainder.find(target) != remainder.end()) {
				if(remainder[target] + 1 < i) return 1;
			}
			else remainder[target] = i;
		}
		return 0;
	}
};
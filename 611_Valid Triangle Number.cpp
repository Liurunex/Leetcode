class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = nums.size()-1; i >= 2; -- i) {
			//if (i < nums.size()-1 && nums[i] == nums[i+1]) continue;
			dfsbacktracking(nums, res, i);
		}
		return res;
	}

	void dfsbacktracking(vector<int>& nums, int& res, int start) {
		int left = 0, right = start-1;
		while (left < right) {
			/*while (left < start && nums[left] == nums[++ left]);
			while (right >= 0 && nums[right] == nums[-- right]);
			left --;
			right ++;*/

			if (nums[left] + nums[right] > nums[start]) {
				res += right - left;
				right --;
			}
			else left ++;
		}
	}
};
/* the idea: similar to 3Sum, the difference is we cannot iterate from
 * begin to end, instead, we should first identify the longest number,
 * and then iterate to find the two short one, the thoughts inside is
 * we want the two unidentified number stay on the same side of the
 * inequvalience; NOTICE no need to remvoe duplicates in this question
 */
/* TLE */
class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		vector<int> candi;
		dfsbacktracking(nums, res, 0, candi);
		return res;
	}

	void dfsbacktracking(vector<int>& nums, int& res, int start, vector<int>& candi) {
		if (candi.size() == 3) {
			if (candi[0] + candi[1] > candi[2]) 
				res ++;
			return;
		}

		for (int i = start; i < nums.size(); ++ i) {
			if (!nums[i]) continue;
			candi.push_back(nums[i]);
			dfsbacktracking(nums, res, i+1, candi);
			candi.pop_back();
		}
	}
};

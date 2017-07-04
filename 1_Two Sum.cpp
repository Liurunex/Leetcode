class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<pair<int, int>> mnums;
        for (int i = 0; i < nums.size(); ++ i)
        	mnums.push_back(make_pair(nums[i], i));
        

        sort(mnums.begin(), mnums.end());
        int left = 0, right = nums.size()-1;
        while (left < right) {
        	int sum = mnums[left].first + mnums[right].first;
        	if (sum == target) {
        		res.push_back(mnums[left].second);
        		res.push_back(mnums[right].second);
        		return res;		
        	}
        	else if (sum > target) right --;
        	else left ++;
        }
        return res;
    }
};
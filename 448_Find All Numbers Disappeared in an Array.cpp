/* the array algorithm: consider the index involved with value, 
especially for question 1~n store in array[n], use negation is a good choice  */
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
		for (int i = 0; i < nums.size(); ++ i) {
			int index = abs(nums[i])-1;
			if (nums[index] > 0) nums[index] *= -1;
		}

		for (int i = 0; i < nums.size(); ++ i) {
			if (nums[i] > 0)
				res.push_back(i+1);
		}
		return res;
	}
};
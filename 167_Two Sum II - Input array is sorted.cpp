class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size()-1;
		while (left < right) {
			if (numbers[left] + numbers[right] == target) {
				vector<int> res;
				res.push_back(left+1);
				res.push_back(right+1);
				return res;
			}
			else if (numbers[left] + numbers[right] > target)
				right --;
			else left ++;
		}
	}
};
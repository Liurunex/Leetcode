class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		
		for (int i = 31; i >= 0; -- i) {
			int digit_counter = 0;
			for (int number:nums)
				digit_counter += (number >> i) & 1;
			res <<= 1;
			res += digit_counter%3;
		}
		return res;
	}
};
/* the idea: consider each digit: since each number appears 3 times
 * except the target, that indicate each digit should be 3*m + value
 * of target on that digit, based on that, our solution is to go check
 * each digit one by one and compute its remainder, the final result after
 * computing all digits is the target obviously
 */
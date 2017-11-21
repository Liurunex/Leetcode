class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (int i = left; i <= right; ++ i) {
			int num = i;
			while (num) {
				int digit = num % 10;
				if (!digit || i%digit)
					break;
				num /= 10;
			}
			if (!num)
				res.push_back(i);
		}
		return res;
	}
};

/* the idea: just iterate through each number and test
 * if it is a "driven" number
 */
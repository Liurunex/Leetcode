class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int add = 1;
		for (int i = digits.size()-1; i >= 0; -- i) {
			digits[i] += add;
			add = 0;
			if (digits[i] > 9) {
				digits[i] = 0;
				add = 1;
			}
			else break;
		}

		if (add) {
			digits.push_back(add);
			int switch_n = add;
			for (int i = 0; i< digits.size(); ++ i) {
				int tem = digits[i];
				digits[i] = switch_n;
				switch_n = tem;
			}
		}
		return digits;
	}
};
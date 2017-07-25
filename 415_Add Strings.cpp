class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1.length() < num2.length()) return addStrings(num2, num1);
		int carry = 0;
		auto i = num1.rbegin();
		auto j = num2.rbegin();
		while (j != num2.rend()) {
			int sum = (*i) - '0' + (*j) - '0' + carry;
			if (sum > 9) {
				carry = 1;
				sum -= 10;
			} 
			else carry = 0;
			*i = sum + '0';
			i ++;
			j ++;
		}

		while (carry) {
			if (i == num1.rend()) {
				num1 = "1" + num1;
				break;
			}
			int sum = (*i) - '0' + carry;
			if (sum > 9) {
				carry = 1;
				sum  -= 10;
			}
			else carry = 0;
			*i = sum + '0';
			i ++;
		}
		return num1;
	}
};
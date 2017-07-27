/* need reconsider */
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.length() < num2.length()) return multiply(num2, num1);
		if (num2.length() == 1 && num2[0] == '0') return "0";
		int carry = 0, zero_tail = 0;
		string inproduct, productres;
		for (int j = num2.length()-1; j >= 0; -- j) {
			int carry = 0;
			inproduct.clear();
			for (int i = num1.length()-1; i >= 0; -- i) {
				int temp = (num1[i] - '0') * (num2[j] - '0') + carry;
				if (temp > 9) {
					carry      = temp/10;
					string single(1, temp%10 + '0');
					inproduct  = single + inproduct;
				}
				else {
					carry = 0;
					string single(1, temp + '0');
					inproduct  = single + inproduct;
				}
			}
			if (carry) {
				string carry_digit(1, carry + '0');
				inproduct = carry_digit + inproduct;
			}
			string addzero(zero_tail, '0');
			inproduct += addzero;
			zero_tail ++;
			productres = addStrings(productres, inproduct);
		}
		return productres;
	}

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
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> val(num1.size()+num2.size(), 0);
        
        for (int i = num1.size()-1; i >= 0; --i) {
            for (int j = num2.size()-1; j >= 0; --j) {
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int total = mul + val[i+j+1];
                
                val[i+j]   += total/10;
                val[i+j+1] = total % 10;
            }
        }
        string res;
        int i = 0;
        while (!val[i])
            i ++;
        for (; i < val.size(); ++ i) {
            res += val[i] +'0';
        }
        return res == "" ? "0":res;
    }
};
// m位乘以n位最多(m+n)位结果，对于n1[i] * n2[j] -> 高位放在 res[i+j], 低位放在 res[i+j+1]，得出单位product后，要加上carry也就是res[i+j+1]的值才是本次单位计算结果，然后update res[i+j+1] 和 res[i+j], 注意低位update
//直接assign，高位还要加上高位本来的值！
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
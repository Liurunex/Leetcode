class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int norm_a, prefix_a;
		extract(a, norm_a, prefix_a);
		int norm_b, prefix_b;
		extract(b, norm_b, prefix_b);
		int norm   = norm_a*norm_b - prefix_a*prefix_b;
		int prefix = norm_a*prefix_b + prefix_a*norm_b;
		return to_string(norm) + "+" + to_string(prefix)+"i";
	}

	void extract(string& s, int& norm, int &prefix) {
		char presym = '+';
		for (int i = 0; i < s.length(); ++ i) {
			if (s[i] >= '0' && s[i] <= '9') {
				int number = 0;
				while (i < s.length() && s[i] >= '0' && s[i] <= '9')
					number = number*10 + s[i ++] - '0';
				i --;
				number *= presym == '+' ? 1:-1;
				if (s[i+1] == 'i')
					prefix = number;
				else norm = number;
			}
			else presym = s[i];
		}
	}
};
/* the idea: math problem, just divide the natural part and complex part and you are done */
/* short solution: we use istringstream to split the string into natural and complex parts*/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        istringstream is1(a), is2(b);
        int a1, a2, b1, b2, r1, r2;
        char plus;
        is1 >> a1 >> plus >> a2;
        is2 >> b1 >> plus >> b2;
        r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};
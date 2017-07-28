/* start from position n-1, go from end to start */
class Solution {
public:
	int titleToNumber(string s) {
		int digit = 0, res = 0;
		while (s.length() > 0) {
			char cur = s.back();
			s.pop_back();
			res += pow(26,digit) * (cur-'A'+1);
			digit ++;
		}	
		return res;
	}
};
/* start from position 0, go from start to end */
class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (int i = 0; i < s.length(); ++ i) {
			res *= 26;
			res += s[i]-'A'+1;
		}
		return res;
	}
};
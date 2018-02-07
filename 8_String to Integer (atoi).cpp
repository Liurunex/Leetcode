class Solution {
public:
	int myAtoi(string str) {
		if (!str.size()) return 0;
		int i = 0;
		while (i < str.size() && str[i] == ' ')
			i ++;
		if (i >= str.size()) return 0;
		int sign = 1;
		if (str[i] != '+' && str[i] != '-' && !isdigit(str[i]))
			return 0;
		if (str[i] == '+' || str[i] == '-')
			sign = str[i ++] == '-' ? 0:1;
		long res = 0;
		while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
			res = res*10 + str[i]-'0';
			if (res > INT_MAX)
				return sign ? INT_MAX:INT_MIN;
			++ i;
		}
		return sign ? (int)res:(int)res*-1;
	}
};

/* the idea: 细心题：开头跳space，第一个字符判断正负，考虑越界问题*/
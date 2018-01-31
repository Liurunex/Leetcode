class Solution {
public:
	int countBinarySubstrings(string s) {
        if (s.size() < 1) return 0;
		char pre = s[0];
		int aSize = 1, bSize = 0, res = 0;

		for (int i = 1; i < s.size(); ++ i) {
			if (s[i] == pre)
				aSize ++;
			else {
				pre = s[i];
				res += min(aSize, bSize);
				bSize = aSize;
				aSize = 1;
			}
		}
        res += min(aSize, bSize);
		return res;
	}
};

/* the idea: 遍历，记录两个不同符号连续的长度，当发现符号反转，则update result，
 * 注意要看result应该加上之前记录的两个长度较小者，然后重置和更新两个长度值；NOTICE
 * 跳出for loop后还应该再更新一次！*/
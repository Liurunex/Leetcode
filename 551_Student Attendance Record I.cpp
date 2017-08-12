class Solution {
public:
	bool checkRecord(string s) {
		int absent = 0, clate = 0;
		for (int i = 0; i < s.length(); ++ i) {
			if (s[i] == 'A') {
				if (absent) return false;
				absent ++;
				continue;
			}
			if (s[i] == 'L') {
				if (i > 0 && s[i-1] == 'L') clate ++;
				else clate = 1;
				if (clate > 2) return false;
			}
		}
		return true;
	}
};
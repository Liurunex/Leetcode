class Solution {
public:
	int lengthOfLastWord(string s) {
		if (!s.length()) return 0;
		int res = 0;
		for (int i = s.length()-1; i >= 0; -- i) {
			if (s[i] == ' ' && res != 0) break;
			if (s[i] != ' ') res ++;
		}
		return res;
	}	
};
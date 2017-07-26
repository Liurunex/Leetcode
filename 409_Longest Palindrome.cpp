class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> dic;
		for (int i = 0; i < s.length(); ++ i) {
			if (dic.find(s[i]) != dic.end())
				dic[s[i]] ++;
			else dic[s[i]] = 1;
		}
		int len = 0;
		int hasone = 0;
		for (auto i = dic.begin(); i != dic.end(); ++ i) {
			len += i->second/2;
			i->second %= 2;
			hasone = i->second || hasone;
		}

		return hasone ? len*2+1:len*2;
	}
};
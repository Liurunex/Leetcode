class Solution {
public:
	char findTheDifference(string s, string t) {
		unordered_map<char, int> dic;
		for (int i = 0; i < s.length(); ++ i) {
			if (dic.find(s[i]) == dic.end())
				dic[s[i]] = 1;
			else dic[s[i]] ++;
		}
		for (int i = 0; i < t.length(); ++ i) {
			if (dic.find(t[i]) == dic.end())
				return t[i];
			dic[t[i]] --;
			if (dic[t[i]] < 0) return t[i];
		}
	}
};

/* better one : x^0 = x, x^x = 0 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};
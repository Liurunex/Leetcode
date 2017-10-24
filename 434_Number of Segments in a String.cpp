class Solution {
public:
	int countSegments(string s) {
		int res = 0, i = 0;
		while (i < s.length() && s[i] == ' ')
			++ i;
		for (; i < s.length(); ++ i) {
			if (s[i] != ' ') {
				res ++;
				while (i < s.length() && s[i] != ' ')
					i ++;
			}
		}
		return res;
	}
};
/* the idea: basic a split string question, notice the empty case
 */

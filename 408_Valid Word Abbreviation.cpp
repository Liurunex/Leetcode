class Solution {
public:
	bool validWordAbbreviation(string word, string abbr) {
		int wi = 0, wa = 0;
		while (wa < abbr.length() && wi < word.length()) {
			if (abbr[wa] >= '0' && abbr[wa] <= '9') {
				if (abbr[wa] == '0') return false;
				int ab_len = 0;
				while (wa < abbr.length() && abbr[wa] >= '0' && abbr[wa] <= '9')
					ab_len = ab_len*10 + abbr[wa ++]-'0';
				wi += ab_len;
			}
			else
				if (abbr[wa ++] != word[wi ++]) return false;
		}
		return wi == word.length() && wa == abbr.length();
	}
};

/* the idea: simple iteration, notice the while terminate condition
 * is to judege both string, otherwise overflow migh happen
 */

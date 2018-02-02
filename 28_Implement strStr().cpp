class Solution {
public:
	int strStr(string haystack, string needle) {
		int hi = 0, ni = 0, start = 0;
		while (hi < haystack.size() && ni < needle.size()) {
			if (haystack[hi] == needle[ni]) {
				hi ++;
				ni ++;
			}
			else {
				start ++;
				hi = start;
				ni = 0
			}
		}
		if (ni >= needle.size())
			return start;
		return -1;
	}
};
/* the idea: 简单two pointer做法，有KMP的做法*/
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
	/**
	* @param buf Destination buffer
	* @param n   Maximum number of characters to read
	* @return    The number of characters read
	*/
	int read(char *buf, int n) {
		int res = 0;
		while (n > res) {
			int tem = read4(buf + res);
			if (!tem) break;
			res += tem;
		}
		return min(res, n);
	}
};

/* NOTICE: the trick here is return value, since n might < res, e.g. read("ab", 1)
the res become 2 while n is still 1 */
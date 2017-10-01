class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		if (!B.length() || !A.length()) return 0;
		int res = INT_MAX;
		for (int i = 0; i < A.length(); ++ i) {
			if (A[i] == B[0])
				checkif(A, B, res, i);
		}
		return res == INT_MAX ? -1:res;
	}

	void checkif(string& A, string& B, int& res, int start) {
		int curres = 1, b_index = 0;  
		while (b_index < B.length()) {
			if (A[start ++] == B[b_index ++]) {
				if (b_index >= B.length()) break;
				if (start >= A.length()) {
					start = 0;
					curres ++;
				}
				continue;
			}
			return;
		}
		res = min(res, curres);
	}
};
/* the idea: brute force idea, we check A until find A[i] == B[0], then call
 * a fucntion to caculate the number of A's we need to construct B, do this for
 * each cases A[i] == B[0], and update the res each time
 */

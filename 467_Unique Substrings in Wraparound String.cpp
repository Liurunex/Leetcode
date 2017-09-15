class Solution {
public:
	int findSubstringInWraproundString(string p) {
		if (!p.length()) return 0;
		int curlen = 1;
		vector<int> alphaDp (26, 0);
		alphaDp[p[0]-'a'] = 1;		
		for (int i = 1; i < p.length(); ++ i) {
			int pos = p[i] - 'a';
			if (p[i]-1 == p[i-1] || (p[i] == 'a' && p[i-1] == 'z'))
				curlen ++;
			else curlen = 1;
			alphaDp[pos] = max(alphaDp[pos], curlen);
		}
		int res = 0;
		for (int i = 0; i < 26; ++ i)
			res += alphaDp[i];
		return res;
	}
};
/* the idea: to find all the subtring in wraparound alphabet order, we must notice all
 * the valid substring is either a single char or a substring in wrapoud alphabet; in
 * addition, notice that the substring [i..j] contains all substings end at j; so that
 * we change the question to find the maxmium length of contiguous subarry in p end at
 * each character from 'a' to 'z' respectively;
 * we use a vector[26] to record all the 26 cases, count and unpated the corresponding
 * one in single traversal;
 * NOTICE: we must update vector[i] each time before next loop since there might be 
 * multiple substring end at same character in wraparound alphabet order
*/

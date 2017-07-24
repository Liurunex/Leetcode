class Solution {
public:
    bool isSubsequence(string s, string t) {
    	if (s.length() > t.length()) return false;
        int i = 0, j = 0;
        while (1) {
        	if (i > s.length()) return true;
        	if (j > t.length()) return false;
        	if (s[i] == t[j]) {
        		i ++;
        		j ++;
        	}
        	else j ++;
        }
    }
};

/* consider the follow up using binary search */
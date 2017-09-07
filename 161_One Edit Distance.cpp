class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length() < t.length()) { string tem = s; s = t; t = tem; }
        int diff = s.length()-t.length();
        switch (diff) {
        	case 0: {
        		int countdiff = 0;
        		for (int index = 0; index < t.length(); ++ index) {
        			if (s[index] != t[index]) {
        				if (countdiff == 1)
        					return false;
        				else countdiff ++;
        			}
        		}
    			return countdiff == 1;
        	}
        	case 1: {
        		for (int index = 0; index < t.length(); ++ index)
        			if (s[index] != t[index])
        				return s.substr(index+1) == t.substr(index);
        		return true;
        	}
        	default: return false;
        }

    }
};

/*
the idea is simple: just consider three cases:
diff > 1, false;
diff == 1, remove the extra character to see if equal
diff == 0, change exact one character to see result
 */
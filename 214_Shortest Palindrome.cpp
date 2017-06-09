/*
solution 1: s: B->M<-B<-A; r: A->B->M<-B; find the substr B->M<-B
solution 2: KMP next function, " " is necessary to divide rerverse string and original one
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rever = s;
        reverse(rever.begin(), rever.end());
        int i = 0, n = s.size();
        for (i = n; i >=0; i--) {
        	if (s.substr(0, i) == rever.substr(n-i))
        		break;
        }
        return rever.substr(0, n-i) + s;
    }
};

/*
solution 2: KMP next function, " " is necessary to divide rerverse string and original one
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rever = s;
        reverse(rever.begin(), rever.end());
        string p = s + " " + rever + " ";

        vector<int> next(p.size(), -1); 
        int i = 0;
        int k = -1;
        while (i < p.size()-1) {
        	if (k < 0 || p[i] == p[k]) 
        		next[++i] = ++k;
        	else
        		k = next[k];
        }
        return rever.substr(0, s.size()-next.back()) + s;
    }
};
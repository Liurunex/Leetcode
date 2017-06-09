class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        char tem;
        
        for (i = 0; i < s.size(); i++) {
            if (i == s.size()/2)
                break;
          
            tem = s[i];
            s[i] = s[s.size()-i-1];
            s[s.size()-i-1]= tem;
        
        }
        return s;
    }
};
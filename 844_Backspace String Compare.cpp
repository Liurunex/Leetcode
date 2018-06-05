class Solution {
public:
	bool backspaceCompare(string S, string T) {
		string s = help(S);
        string t = help(T);
        return s == t;
	}

	string help(string &str) {
        string nstr = "";
        for (char ac:str) {
            if (ac == '#') {
                if (nstr.size() > 0)
                    nstr.pop_back();
            }
            else
                nstr += ac;
        }
        return nstr;
	}
};
/* the idea: dont do it in reverse order, sine the result is deceided in
   normal order
 */
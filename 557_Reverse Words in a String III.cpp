class Solution {
public:
    string reverseWords(string s) {
    	int wordstart = s.find_first_not_of(" ");
    	for (int i = 0; i <= s.length(); ++ i) {
    		if (s[i] == ' ' || i == s.length()) {
    			reverse(&s[wordstart], &s[i]);
    			wordstart = i+1;
    		}
    	}
    	return s;
    }
};
/* the idea: the initial idea is to use istringstream to split
 * the word by put into iostream, and then call the reverse fucntion;
 * NOTICE the istringstream will generate a additioanl " " word so that
 * the trick is the end of the operated-string has a series of 0 in the 
 * trail and we should remvoe all of them;
 * a better way is just traveal the given word, we set a var to store
 * the start index of the current word, once we met the end of the string
 * or met ' ' we do the reverse action, and update the word start index
 * NOTICE the reverse fucntion is [start, end)
 * /

class Solution {
public:
    string reverseWords(string s) {
    	if (s.length() < 2) return s;
    	string res;
    	istringstream iss(s);
    	while (iss) {
    		string subs;
    		iss >> subs;
    		reverse(subs.begin(), subs.end());
    		res += subs + " ";
    	}   
    	while (res.back() == ' ')
    		res.pop_back();
    	return res;
    }
};

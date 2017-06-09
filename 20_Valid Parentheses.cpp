class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2 != 0) return false;
		stack<char> mystack;
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
				case '(':
				case '{':
				case '[': mystack.push(s[i]); break;
				case ')':
				case '}':
				case ']': 
				    if (mystack.empty() || !isMatched(mystack.top(), s[i])) return false; 
					else mystack.pop(); break;
				default: return false;
			}
		}
		return mystack.empty();
	}

	bool isMatched(char front, char back) {
	    bool re = false;
		switch (front) {
			case '(': if (back == ')') re = true; break;
			case '{': if (back == '}') re = true; break;
			case '[': if (back == ']') re = true; break;
			default: ;
		}
		return re;
	}
};
class Solution {
public:
    string decodeString(string s) {
		string res = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				int time = s[i] - '0';
				while (i+1 < s.length() && s[i+1] >= '0' && s[i+1] <= '9')
					time = time*10 + (s[++i] - '0');
				i += 2;
				pair<int, string> content = decodHelp(s, i);
				i = content.first;
				while (time > 0) {
					res += content.second;
					time --;
				}
				time = 0;
			}
			else res += s[i];
		}

		return res;
    }

    pair<int, string> decodHelp(string s, int i) {
    	string content = "";
    	for (; i < s.length(); i ++) {
    		if (s[i] >= '0' && s[i] <= '9') {
    			int time = s[i] - '0';
    			while (i+1 < s.length() && s[i+1] >= '0' && s[i+1] <= '9')
					time = time*10 + (s[++i] - '0');
    			i += 2;
    			pair<int, string> subContent = decodHelp(s, i);
    			i = subContent.first;
    			while (time > 0) {
    				content += subContent.second;
    				time --;
    			}
    		}
			else if (s[i] == ']') 
				return make_pair(i, content);
			else content += s[i];
    	}
    }
};
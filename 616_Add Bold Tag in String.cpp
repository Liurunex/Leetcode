class Solution {
public:
	string addBoldTag(string s, vector<string>& dict) {
		vector<int> marked (s.length(), 0);
		int flip_end = -1;
		for (int i = 0; i < s.length(); ++ i) {
			for (int j = 0; j < dict.size(); ++ j) {
				int len = dict[j].length();
				if (i+len-1 < s.size() 
					&& s.substr(i, dict[j].length()) == dict[j])
					flip_end = max(flip_end, i+len-1);
			}
			marked[i] = i > flip_end ? 0:1;
		}
		string res;
        int index = 0;
		while(index < s.length()) {
			if (!marked[index]) res += s[index];
			else {
				res += "<b>";
				while (index < s.length() && marked[index]) res += s[index++];
				res += "</b>";
                continue;
			}
            index ++;
		}
        cout << res;
		return res;
	}
};
/* the idea: brute force idea: we use a marked vector to represent if the char is marked as bold;
 * start from each character in string, check each words in dict matching substring start at our
 * current index i, then fill in the marked vector based on the updated end_bound which denote the
 * boundary, this is the key part: for i, we iterate all words and decide the last element from i
 * that can be bold by matching one word, we will only assign marked[i] for once
 */

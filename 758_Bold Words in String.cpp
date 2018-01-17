class Solution {
public:
	string boldWords(vector<string>& words, string S) {
		vector<int> flipmap(S.size(), 0);
		int flip_end = -1;
		for (int i = 0; i < S.size(); ++ i) {
			for (auto str:words) {
				int len = str.size();
				if (i+len-1 < S.size() && S.substr(i, len) == str)
					flip_end = max(flip_end, i+len-1);
			}
			flipmap[i] = i > flip_end ? 0:1;
		}

		string res;
		for (int i = 0; i < S.size(); ++ i) {
			if (!flipmap[i])
				res += S[i];
			else {
				res += "<b>";
				while (i < S.size() && flipmap[i])
					res += S[i++];
				res += "</b>";
				-- i;
			}
		}
		return res;
	}
};

/* the idea: same as 616, brute force idea: we use a marked vector to represent if the char is marked as bold;
 * start from each character in string, check each words in dict matching substring start at our
 * current index i, then fill in the marked vector based on the updated end_bound which denote the
 * boundary, this is the key part: for i, we iterate all words and decide the last element from i
 * that can be bold by matching one word, we will only assign marked[i] for once
 */
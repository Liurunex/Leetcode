class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<string, char> stoc;
		unordered_map<char, string> ctos;
		istringstream iss(str);
		string cur;
		int i = 0;
		while (iss >> cur) {
			if (i >= pattern.length()) return false;
			if (stoc.count(cur) && stoc[cur] != pattern[i])
				return false;
			if (ctos.count(pattern[i]) && ctos[pattern[i]] != cur)
				return false;
			stoc[cur]        = pattern[i];
			ctos[pattern[i]] = cur;
			i ++;
		}
		return i == pattern.length();
	}
};
/* the idea: double hash table */
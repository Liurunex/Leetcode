class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() != t.length()) return false;
		unordered_map<char, char> dict;
		unordered_set<char> helpdict;
		for (int i = 0; i < s.length(); ++ i) {
			if (dict.find(s[i]) != dict.end()) {
				if (dict[s[i]] != t[i])
					return false;
			}
			else if (helpdict.count(t[i]))
				return false;
			helpdict.insert(t[i]);
			dict[s[i]] = t[i];
		}

		return true;
	}
};

/* the idea: using a hashmap to reord the coreesponding char from s to t, and
 * a hashset to record the items we have checked in t; then do the simple check
 * process, once find the s[i]->t[j] is existed, check if t[j] = t[i], or if not
 * find s[i] key in hashmap, check t[i] has already been added into hashset
 */

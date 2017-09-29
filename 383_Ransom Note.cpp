class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> dict;
		for (char elem:magazine)
			dict[elem] ++;
		for (char nelem:ransomNote) {
			if (dict.find(nelem) == dict.end() || dict[nelem] == 0)
				return false;
			dict[nelem] --;
		}
		return true;
	}
};

/* the idea: very simple and straightforward hashtable quesiton */
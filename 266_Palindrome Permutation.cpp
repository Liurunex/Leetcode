class Solution {
public:
	bool canPermutePalindrome(string s) {
		unordered_map<char, int> dict;
		for (char i:s)
			dict[i] += 1;
		int count_odd = 0;
		for (auto i = dict.begin(); i != dict.end(); ++ i) {
			if ((i->second%2))
				count_odd ++;
            if (count_odd > 1) return false;
		}
		return true;
	}
};
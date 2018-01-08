class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i = 0, j = 0, res = 0;
		unordered_map<char, int> dict;
		while (j < s.size()) {
			dict[s[j]] ++;
			while (dict.size() > k) {
                if (!(-- dict[s[i]]))
					dict.erase(s[i]);
                i ++;
            }
			res = max(res, 1-i+(j++));
		}

		return res;
    }
};

/* the idea: slipping window + two pointer + hashmap. We set two
 * pointers, one for leftbound, one for rightbound; the hashmap
 * mapped the char to its appearing times in the slipping window.
 * Keep increase the rightbound pointer and so as the char's values
 * inside the hash-map. Once we found the hashmap has more than 2
 * entries, we need to move the leftbound pointer and so as reduce
 * the char's appearing times in hashmap until the hashmap has no
 * more than 2 entries.
 */
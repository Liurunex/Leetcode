class Solution {
public:
	string reverseVowels(string s) {
		unordered_set<char> dict ({'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'});
		int left = 0, right = s.length()-1;
		while (left < right) {
			while (!dict.count(s[left])) left ++;
			while (!dict.count(s[right])) right --;
            if (left >= right) return s; 
			swap(s[left ++], s[right --]);
		}
		return s;
	}
};
/* the idea: intuitive a tow pointer + unorderset problem;
 * Notice the vowels contains both upper-lowercase letter
 */
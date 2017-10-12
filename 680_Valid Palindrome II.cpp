class Solution {
public:
	bool validPalindrome(string s) {
		return helper(s, 0, s.length()-1, 1);
	}

	bool helper(string& s, int left, int right, int delet) {
		if (left >= right) return true;

		if (s[left] == s[right])
			return helper(s, left+1, right-1, delet);
		else {
			delet --;
			if (delet < 0) return false;
			return helper(s, left+1, right, delet) ||
			helper(s, left, right-1, delet);
		}
	}
};
/* the idea: just do recursive call to determine both removeing left and
 * right cases, notice the false return condition is you cannot delete
 */

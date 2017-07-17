class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.size()-1, skip;
		while (right > left) {
			while (left < right && !(s[left]-'0' >= 0  && '9'-s[left] >= 0)   
				&& !(tolower(s[left])-'a' >= 0 && 'z'-tolower(s[left]) >= 0))
				left ++;
			while (right > left && !(s[right]-'0' >= 0 && '9'-s[right] >= 0) 
				&& !(tolower(s[right])-'a' >= 0 && 'z'-tolower(s[right]) >= 0))
				right --;
			
			if ((!(s[left]-'0' >= 0  && '9'-s[left] >= 0) && !(tolower(s[left])-'a' >= 0 && 'z'-tolower(s[left]) >= 0)) || 
				(!(s[right]-'0' >= 0 && '9'-s[right] >= 0) && !(tolower(s[right])-'a' >= 0 && 'z'-tolower(s[right]) >= 0))) {
				cout << "out";
                return true;
            }

			if (s[left] == s[right] || tolower(s[left]) == tolower(s[right])) {
				left  ++;
				right --;
				continue;
			}

			return false;
		}
		return true;
	}
};
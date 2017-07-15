/* the case like 100 should be consider seperately, 
since it always conform the condition x > reserse;
 */
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (!(x&10) && x) return fasle;

		int reverse = 0;

		while (x > reverse) {
			reverse = reverse*10 + x%10;
			x /= 10;
		}

		return (x == reverse || x == reverse/10);
	}
};
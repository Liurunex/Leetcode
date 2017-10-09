class Solution {
public:
	bool hasAlternatingBits(int n) {
        int plast = n&1;
		while (n) {
            n >>= 1;
			if(!(n&1)^plast)
				return false;
			plast = n&1;
		}
		return true;
	}
};
/* the idea: just use ^ to compare last digit of p and the last digit of p>>1;
 * the trick: the ^ operation in atom
 */

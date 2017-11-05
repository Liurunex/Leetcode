class Solution {
public:
	int integerReplacement(int n) {
		if (n == 1) return 0;
		if (!(n&1)) return 1 + integerReplacement(n>>1);
		else {
			return 2+min(integerReplacement(((long long)n+1)/2), integerReplacement((n-1)/2));
		}
	}
};

/* the idea: brute force recursion: if even we recursive call n>>1, if odd, return the
 * min value from case (n+1)/2 and (n-1)/2
 */
class Solution {
public:
	bool isPowerOfThree(int n) {
		double a = (log10(n)/log10(3));
        return a == (int)a;
	}
};

/* the idea: math. Consider log, loga(b) = logc(b)/logc(a), go check
 * if log10(n)/log10(3) is int */
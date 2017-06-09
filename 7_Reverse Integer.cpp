class Solution {
public:
    int reverse(int x) {
	   if (!x) return x;
        long long res = 0;
        int negative = 0;
        if (x < 0) negative = 1;
	   x = abs(x);
        while (x > 0) {
		   res = res*10 + x%10;
		   x /= 10;
        }
	   res = negative ? res*-1 : res;
	   return (res < INT_MIN || res > INT_MAX) ? 0 : res;
    }
};

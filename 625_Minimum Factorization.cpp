class Solution {
private:
	string minium;
public:
	int smallestFactorization(int a) {
		if (a == 1) return a;
		helper(a, 9);
		if (a != 1) return 0;
		return stoll(minium) > INT_MAX ? 0:(int)(stoll(minium));
	}
	
	void helper(int &a, int i) {
		if (a == 1 || i == 1)
			return;
		while (!(a%i)) {
			minium = to_string(i) + minium; 
			a /= i;
		}
		helper(a, i-1);
	}	
};
/* notice that you should consider the case wherer divisor appeared multiple time  */

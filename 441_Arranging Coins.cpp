class Solution {
public:
	int arrangeCoins(int n) {
		return int(sqrt((1+8*(double)n))/2-0.5);
	}
};

/* this is a trick */
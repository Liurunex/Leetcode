class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num <= 1) return true;
		size_t left = 1, right = num;
		while (left <= right) {
			size_t mid = left + (right-left)/2;
			if (mid*mid > num) right = mid - 1;
			else if (mid*mid < num) left = mid + 1;
			else return true;
		}
	    return false;
	}
};

/* notice to change the left, mid, right to be long or size_t to avoid overflow of int*/
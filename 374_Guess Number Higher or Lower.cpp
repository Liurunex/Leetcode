// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int left = 1, right = n, mid = 0, result = 0;
		
		while (left <= right) {
			mid = left+(right-left)/2;
			result = guess(mid);
			if (!result) return mid;
			else if (result == -1) right = mid-1;
			else left = mid+1;
		}
	}
};

/* the idea: basic binary search question
 */
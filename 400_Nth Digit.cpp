class Solution {
public:
	int findNthDigit(int n) {
		long long len = 1, count = 9, start = 1;

		/* find the nth number located in which x-digit number range */
		while (n > len*count) {
			n -= len*count;
			len ++;
			count *= 10;
			start *= 10;
		}

		/* find the number that the nth digit is in */
		start += (n-1)/len;
		string target = to_string(start);

		/* find the nth digit in previous number */
		return target[(n-1) % len] - '0';
	}
};

/* the idea: Math. Consider that there is 9 1-digit number, 90 2-digit number,
 * 900 3-digit number etc. So that we need to determine which range our target
 * is in, then find the number and then the nth digit
 * Three steps to go: 
 * step_1: find the nth number located in which x-digit range
 * step_2: find the number that the nth digit is in 
 * step_3: find the nth digit in the previous number of step_2 
 */
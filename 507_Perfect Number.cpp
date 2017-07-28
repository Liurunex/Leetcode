class Solution {
public:
	bool checkPerfectNumber(int num) {
		int res = 0;
		for (int i = 2; i < sqrt(num); ++ i) {
			if (!(num%i)) {
				res += i + num/i;
            }
		}
        if (num == sqrt(num)*sqrt(num)) res += sqrt(num);
		return res+1 == num;
	}
};
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
		for (int it : nums) {
			if (it > first) {
				third  = second;
				second = first;
				first  = it;
			}	
			else if (it > second && it < first) {
				third  = second;
				second = it; 
			}
			else if (it > third && it < second) 
				third = it;
		}
		return (third == LONG_MIN || third == second) ? first:third;
	}
};

/*
the trick: one is you must inital the three number as long type with initial 
vlaue LONG_MIN, this is to solve the issue when input contain INT_MIN; another 
one is that the order of first, second and third is strict, that means:
first > second > third, no = is allowed, therefore in you if statement you
must compelete the inequility
 */
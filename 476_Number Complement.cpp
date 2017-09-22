class Solution {
public:
	int findComplement(int num) {
		int dummy = INT_MAX;
		while (dummy & num)
			dummy <<= 1;
		return ~dummy & ~num;
	}
};

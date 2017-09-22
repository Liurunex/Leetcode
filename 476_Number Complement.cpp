class Solution {
public:
	int findComplement(int num) {
		int dummy = INT_MAX;
		while (dummy & num)
			dummy <<= 1;
		return ~dummy & ~num;
	}
};

/* the idea: try to use ~, but it will also
 * flip the sign bit will be affected, e.g.:
 * ~(0000 1010) lead to (1111 0101), to solve
 * this, we want a binary (1111 0000), which
 * will fliter the uninteneded sign bit; 
 * therefore we use INT_MAX to & with target
 * by left move INT_MAX until the (int_max)&(target) == 0
 * then we found the highest bit that is not sign bit;
 * do the ~(int_max) to get the fliter, and use the 
 * fliter to & with ~(target)
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int time = 0;
        while (m != n) {
        	m >>= 1;
        	n >>= 1;
        	time ++;
        }
        int res = (m << time)
    	return res;
    }
};
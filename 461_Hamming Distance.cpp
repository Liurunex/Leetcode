class Solution {
public:
    int hammingDistance(int x, int y) {
        if (x == y) return 0;
    	int res = x ^ y;
        res = (res & (0x55555555)) + ((res >> 1) & (0x55555555));
        res = (res & (0x33333333)) + ((res >> 2) & (0x33333333));
        res = (res & (0x0f0f0f0f)) + ((res >> 4) & (0x0f0f0f0f));
        res = (res & (0x00ff00ff)) + ((res >> 8) & (0x00ff00ff));
        res = (res & (0x0000ffff)) + ((res >> 16) & (0x0000ffff));
    	return res;
    }
};


1000  0001  0010  1001 || 0100  0000  1001  0100 
0101  0101  0101  0101 || 0101  0101  0101  0101

1001 0111

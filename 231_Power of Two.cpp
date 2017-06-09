class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        return (n&(n-1)) == 0 && n > 1;
    }
};
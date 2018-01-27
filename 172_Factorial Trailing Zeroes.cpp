class Solution {
public:
    int trailingZeroes(int n) {
        int countFive = 0;
        while (n) {
            countFive += n/5;
            n /= 5;
        }
        return countFive;
    }
};
/* the idea: Math. We are writing a O(logn) alogirthm, just count how many 5 you have */
class Solution {
public:
    int trailingZeroes(int n) {
        int countFive = 0;
        for (int i = 1; i < n+1; ++ i) {
            int  val = i;
            while (val%5 == 0) {
                countFive ++;
                val /= 5;
            }
        }
        return countFive;
    }
};
/* consider the + - * /: http://blog.csdn.net/hackbuteer1/article/details/7390093 */
class Solution {
public:
    int getSum(int a, int b) {
        if (!a) return b;
        if (!b) return a;
        int sum = 0;
        /* view b as the carry til it goes to 0 */
		while (b != 0) {
			sum = a^b; // the add without carry
			b = (a&b) << 1;
			a = sum;
		}
		return sum;
    }
};
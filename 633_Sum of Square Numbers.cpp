class Solution {
public:
    bool judgeSquareSum(int c) {
		long limit = (int)sqrt(double(c));
		if (limit * limit == (long)c) return true;
		
		for (long i = 1; i <= limit; ++ i) {
			long j = c - i*i;
			long testJsqurt = (int)sqrt(double(j));
			if (testJsqurt * testJsqurt == (long)j) 
				return true;
		}    
		return false;
    }
};
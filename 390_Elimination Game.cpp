class Solution {
public:
	int lastRemaining(int n) {
		if (n == 1) return 1;
		return 2*(1 + n/2 - lastRemaining(n/2));
	}
};

/*
https://discuss.leetcode.com/topic/58042/c-1-line-solution-with-explanation/5

the original sequence: [n = 2k or 2k+1]
    	1 2 3 4 5 6 7 8... n     	-> 
2*(   	  1   2   3   4... n/2 ) 	-> 
2*( 2*( 	  1       2... n/4 )) 	->
consider the mirroing:
1 2 3 4 5... n -> (1,n) (2,n-1) ...
each time our removal + not_removal == k+1, where k = n/2^t
 */
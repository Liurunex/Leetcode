class Solution {
public:
	int kthGrammar(int N, int K) {
		if (N == 1) return 0;
		if (K&1) {
			if (kthGrammar(N-1, (K+1)/2))
				return 1;
			else return 0;
		}
		else {
			if (kthGrammar(N-1, K/2))
				return 0;
			else return 1;
		}
	}
};

/* the idea: recursion + Binary Search thougth. 对N行的K位置，就看N-1行对应的
 * parent是1还是0，这里需要对k分even和odd，是用recursion，其实是bottom up思路
 * */
class Solution {
public:
	int countPrimes(int n) {
		vector<int> visited(n, 0);
		int res = 0;
		for (int i = 2; i <= sqrt(n); ++ i) {
			if (visited[i]) continue;
			for (int k = i+i; k < n; k += i)
				visited[k] = 1;
		}
		for (int i = 2; i < n; ++ i)
			if (!visited[i])
				res ++;
		return res;
	}
};
/* idea: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes*/
class Solution {
public:
	int findDerangement(int n) {
		if (n < 2) return 0;
		if (n == 2) return 1; 
		long long p_b2 = 0, p_b1 = 1, cur = -1, modnum = 1000000007;
		/* p_b1 == dp[i-1], p_b2 == dp[i-2], cur = dp[i] */
		for (int i = 3; i <= n; ++ i) {
			cur  = (i-1)*(p_b1 + p_b2) % modnum;
			p_b2 = p_b1;
			p_b1 = cur;
		}
		return cur;
	}
};

/* the idea: the DFS backtracking method will timeout, here we consider a dp solution:
 * think dp[i] denote the numebr of disarrange peremuations up to i; let's say for array
 * [1 ... i], i can be place anywhere in [1...i-1], let's say it goes to jth place, 
 * then [1..j..i] -> [1..i..?] and we want to place j somwhere: two cases: CASE_1: place
 * j at the ith position, which is just switch i with j, in this case, we still have i-2
 * elements to arrange, which is dp[i-2]; CASE_2: don't place j at ith position, then we
 * have i-1 elements to arrange and !! j cannot be at i, that's like j grant the constraints
 * of i, so that it's dp[i-1]; knowing that, we get our dp realtion: dp[i] = (i-1)(dp[i-2]+dp[i-1])
*/
class Solution {
public:
	int findDerangement(int n) {
		int res = 0;
		vector<int> permutation;
		vector<int> visited(n, 0);
		helperDFS(n, res, permutation, visited, -1);
		return res;
	}

	void helperDFS(int& n, int& res, vector<int>& permutation, 
		vector<int>& visited, int curslect) {
		if (permutation.size() == n) {
			res ++;
			return;
		}

		for (int i = 0; i < n; ++ i) {
			if (permutation.size() == i || curslect == i || visited[i]) continue; 
			permutation.push_back(i);
			visited[i] = 1;
			helperDFS(n, res, permutation, visited, i);
			visited[i] = 0;
			permutation.pop_back();
		}
	}
};
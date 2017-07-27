class Solution {
public:
	int numWays(int n, int k) {
		if (!n || !k) return 0;
        if (n == 1) return k;
		vector<int> dp_diff (n+1, 0);
		vector<int> dp_same (n+1, 0);
		dp_diff[1] = k;
		dp_diff[2] = k*(k-1);
		dp_same[1] = k;
		dp_same[2] = k;
		for (int i = 3; i < n+1; ++ i) {
			dp_same[i] = dp_diff[i-1];
			dp_diff[i] = (k-1) * (dp_same[i-1] + dp_diff[i-1]);
		}
		return dp_diff[n] + dp_same[n];
	}
};

/* the key is to use two dp tables */
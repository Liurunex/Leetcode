class Solution {
public:
	int countArrangement(int N) {
		vector<int> visited (N+1, 0);
		int res = 0;
		helperBT(visited, 1, res, N);
		return res;
	}

	void helperBT(vector<int>& visited, int index, int& res, int& N) {
		if (index > N) {
			res ++;
			return;
		}
		for (int i = 1; i < N+1; ++ i) {
			if (!visited[i] && (!(i%index) || !(index%i))) {
				visited[i] = 1;
				helperBT(visited, index+1, res, N);
				visited[i] = 0;
			}
		}
	}
};

/* the idea: basically a backtracing is done, what to remind is that
 * we don't need extra space to record the permutation but we need
 * the visited map to record using case
 * /
/* a solution related to permutation (swap method):
 * http://www.cnblogs.com/grandyang/p/6533276.html
 * /
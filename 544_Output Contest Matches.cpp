class Solution {
public:
	string findContestMatch(int n) {
		vector<string> matches;
		for (int i = 1; i <= n; ++ i)
			matches.push_back(to_string(i));
		while (n) {
			for (int i = 1; i <= (n >> 1); ++ i)
				matches[i-1] = "(" + matches[i-1] + "," + matches[n-i] + ")";
            n >>= 1;
		}
		return matches[0];
	}
};
/* the idea: divide and conquer: vector storing each round cases: eg: intial 1, 2, 3, 4, for round two:
 * (1,4), (2,3), (discard), (discard); the key thought: we know each round we get only
 * n>>1 treams, let (1,4) be the winner of that match, namely we view (1,4) as "new 1"
 * in next round, then the question has divided into subquestion for new_1, new_2, do the
 * same match arrangement again, NOTICE we keep n>>1, the terminate condition is n == 0
 */
class Solution {
public:
	string minWindow(string S, string T) {
		vector<vector<int>> dp (T.size(), vector<int> (S.size(), -1));

		for (int j = 0; j < S.size(); ++ j) {
			if (S[j] == T[0]) dp[0][j] = j;
			else dp[0][j] = j > 0 ? dp[0][j-1]:-1;
		}

		for (int i = 1; i < T.size(); ++ i) {
			for (int j = i; j < S.size(); ++ j) {
				if (T[i] == S[j])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = dp[i][j-1];
			}
		}
		
		int len = INT_MAX, start = INT_MAX;
		for (int j = T.size()-1; j < S.size(); ++ j) {
			if (dp[T.size()-1][j] != -1) {
				int curlen = j - dp[T.size()-1][j] + 1;
				if (curlen < len) {
					start  = dp[T.size()-1][j];
					len = curlen;
				}
				else if (curlen == len)
					start = min(start, dp[T.size()-1][j]);
			}
		}
		
		return start == INT_MAX ? "" : S.substr(start, len);
	}
};

/* the idea: DP problem: dp[i][j] means: the valid start index of S when 
 * we use S[0..j] to match T[0..i], that means T[0..i] inside the S[k..j]
 * and S[k] = T[0], notice there is nooed S[j] == T[i], but that was our
 * minimum length substring candidate condition; the relations is 
 * if S[j] == T[i] -> dp[i][j] = dp[i-1][j-1], otherwise dp[i][j] = dp[i][j-1]
 * you may be confused with the second case, to expalin: when S[i] != T[j]
 * there is two case: one is S[0..i-1] contained T[0..j], so that our current
 * S[0...i] also contain T[0..j] at the start index of dp[i][j-1]! In other 
 * case where S[0..i] didn't contain T[0..j], that means for dp[i][0..j-1] all
 * values is -1, and our dp[i][j] should also be so, to sum up, theose above
 * two cases can generized into one cases dp[i][j] = dp[i][j-1].
 * NOTICE to inital the first column of dp[0][j]; NOTICE how we handle the 
 * computing the minimumn substring at last: that is we go through dp[T.size()-1][j]
 * calculate the current length and updated, notice to also update the start index
 * when the current lenght is equal as preivous golbal one!
 * FINAL TRICK: the return value should be "" if there is no candiate, that means
 * we should judge the value of start == INT_MAX
 */
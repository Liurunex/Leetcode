class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1, 0));

		for (int i = 0; i < dp.size(); ++ i)
			dp[i][0] = i;
		for (int j = 0; j < dp[0].size(); ++ j)
			dp[0][j] = j;

		for (int i = 1; i < word1.size()+1; ++ i) {
			for (int j = 1; j < word2.size()+1; ++ j) {
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else 
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			}
		}
		return dp[word1.size()][word2.size()];
	}
};
/* the idea: classical dp problem: we definet the dp table, where dp[i][j] means
 * the minimum steps to convert word1[0..i-1] to word2[0..j-1], initialize the
 * base case where i = 0 and j = 0 (those case only require deleting or adding);
 * now let's consider the dp relation:
 * for word1[i] == word2[j], dp[i][j] = dp[i-1][j-1] since we need do nothing but
 * only to convert the substring word1[0..i-2] to word2[0..j-2]; 
 * in other cases where the word1[i] != word2[j], we need consider the three 
 * operations:
 * repalcement: dp[i][j] = dp[i-1][j-1]+1
 * deletion:    dp[i][j] = d[i-1][j]+1
 * insertion:   dp[i][j] = dp[i][j-1]+1
 * we choose the minimum value of above three as we dp[i][j];
 */

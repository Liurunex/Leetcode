class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> mindp (n+1, vector<int> (n+1, 0));
		
		for (int j = 1; j <= n ; ++ j) {
			for (int i = j-1; i > 0; -- i) {
				if (j == i+1) mindp[i][j] = i;
				//else if (j == i+2) mindp[i][j] = i+1; // not necessary 
				else {
					mindp[i][j] = INT_MAX;
					for (int k = i+1; k < j; ++ k) {
						int local_max = max(mindp[i][k-1], mindp[k+1][j]) + k;
						mindp[i][j]  = min(local_max, mindp[i][j]);	
					}
				}
			}
		}
		return mindp[1][n];
	}
};

/* the idea: minimax thougths + dp tech: the question is not related to how we guess
 * the answer, but instead computing the guranteened cost lead us to win. 
 * For case [1,2]
 * we should choose 1 as first guess since it cost less(if 1 not correct, we can immediately
 * get 2 without cost, but if we choose 2 and it's not correct, cost 2 is higher)
 * For case[1,2,3]
 * we should choose 2, since once 2 is not correct, we can immediately get right one with guess()
 * feedback, but with other two numbers, cost will be higher (3 is obviously higher than 2, for
 * choosing 1, we then need to choose from [2,3], which will cost 2 as our first case)
 * Let's consider general case [statr...end] 
 * if we pick a number k among the range and it is not correct, our cost will be costdp[start, k-1] + k
 * or costdp[k+1, end] + k, NOTICE that we need find a "guranteen" cost, namely, we don't know the correct
 * number is in [start, k-1] or [k+1, end], we should assume it was in the worst case, so that this turn
 * we play as Min player, so that use max([start..k-1], [k+1..end]); after that, we want to minimize our 
 * cost to get better results, that is we play as Max player, so that using min(res, localmax)!!
 * Using dp reduce computation.
 */


class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> mindp (n+1, vector<int> (n+1, 0));
		return miniMaxHelper(mindp, 1, n);
	}

	int miniMaxHelper(vector<vector<int>>& mindp, int start, int end) {
		if (start >= end) return 0;
        if (mindp[start][end] > 0) return mindp[start][end]; /* important since it helps redundant computing */
		mindp[start][end] = INT_MAX;
		for (int k = start; k <= end; ++ k) {
			int local_max = k + max(miniMaxHelper(mindp, start, k-1), miniMaxHelper(mindp, k+1, end));
			mindp[start][end] = min(local_max, mindp[start][end]);
		}
		return mindp[start][end];
	}
};
class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		vector<int> dict (n, 1);
		vector<int> factorial (n, 1);
		for (int i = 0; i < n; ++ i)
			dict[i] = i+1;
		for (int i = 1; i < n; ++ i)
			factorial[i] = factorial[i-1]*i;

		k --;
		while (res.length() != n) {
			int digit  = k/factorial[dict.size()-1]; 
			int remain = k%factorial[dict.size()-1];
			
			res += '0'+ dict[digit];
			//cout << res << endl;
			
			k = remain;
			dict.erase(dict.begin() + digit);
		}	

		return res;
	}
};
/* the idea: the inital idea is to use backtracking DFS to find the kth permutation, the only trick for that method
 * is remember to add visited map;
 * the better math idea: we notice that for each group of permutaiton start with same numebr of totally (n-1)!, based
 * on this: we divide all permutation into n groups, and each group has (n-1)! permutations, then use (k-1)/(n-1)! we 
 * can find which group the kth permutaiton is in, the update the k to k' where k' is the relative location the kth
 * permutation is, that is k'= (k-1)%(n-1)!, in this single process we have find the most siginificant number of kth permutaion,
 * then we need to find the second siginificant numebr which is the most siginificant number of k'th permutaion in current 
 * group; so that we keep repeating this process until we have find all n digit of our results;
 * the trick: NOTICE n! is a hight-cost opertaion, we neeed to store all fractiorail we need previously in a arrary;
 * the reason why k--: NOTICE (1..n-1)/n = 0, (n..2n-1)/n = 1, that is the quotient at the boundary
 * will be differ: see the eg. divisor is 6(...), therefore we must do the minus operation
 * 0 | 1 2 3 4 5 | 6 7 8 9 10 11 | 12
 * 0 | 0 0 0 0 0 | 1 1 1 1 1  1  | 2
 */
  
class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		bool findit = false;
		vector<int> visitd (n+1, 0);
		thehelper(n, res, k, findit, visitd);
		return (findit ? res:"");
	}

	void thehelper(int& n, string& curper, int& k, bool& findit, vector<int>& visitd ) {
		if (curper.length() == n) {
			k --;
			if (!k) findit = true;
			return;
		}
		for (int i = 1; i <= n; ++ i){
			if (visitd[i]) continue;
			
			curper.push_back('0'+i);
			visitd[i] = 1;
			
			thehelper(n, curper, k, findit, visitd);
			if (findit) return;

			visitd[i] = 0;
			curper.pop_back();
		}

	}
};

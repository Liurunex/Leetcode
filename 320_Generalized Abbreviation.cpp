class Solution {
public:
	vector<string> generateAbbreviations(string word) {
		vector<string> res;
		string candidate;
		dfsBT(res, candidate, word, 0, false);
		return res;
	}

	void dfsBT(vector<string>& res, string& candidate, string& word, int index, bool preNum) {
		if (index == word.size()) {
			res.push_back(candidate);
			return;
		}
		
		candidate += word[index];
		dfsBT(res, candidate, word, index+1, false);
		candidate.pop_back();

		if (!preNum) {
			for (int replace_len = 1; replace_len+index <= word.length(); ++ replace_len) {
				candidate += to_string(replace_len);
				dfsBT(res, candidate, word, index+replace_len, true);
				for (int i = 0; i < to_string(replace_len).length(); ++ i)
					candidate.pop_back();
			}
		}

	}
};

/* the idea: DFS backtracking, the trick part is when we should add a abbreviation or character
 * to candiate: the solution is we give it a order: that is we first add character to do its
 * own DFS, then after backtracking we try to append a character, NOTICE that we use a symbol
 * preNum to determine whether the previous symbol in abbreviation is a number, if is number, we
 * cannot append a new number!! all other part is just like normal dfs backtracking
 */

/* the brilliant idea, but run slowly: 
 * 000 aaa
 * 001 aa1
 * 010 a1a
 * 011 a2
 * 100 1aa
 * 101 1a1
 * 110 2a
 * 111 3
 * the idea is each binary form of a number correspond to a abbreviation!! Based on that, our
 * solution is to construct candiate string according to each number of its binary form; NOTICE
 * that counter should be extraly delt before pushing to result since it might not be counted yet
 */
class Solution {
public:
	vector<string> generateAbbreviations(string word) {
		vector<string> res;
		string candidate;
		for (int target = 0; target < pow(2, word.size()); ++ target) {
			candidate = "";
			int cur_target = target, counter = 0;
			for (int i = 0; i < word.size(); ++ i) {
				int move = word.size()-i-1;
				if ((cur_target >> move) & 1)
					counter ++;
				else {
					if (counter) {
						candidate += to_string(counter);
						counter   = 0;
					}
					candidate += word[i];
				}
			
			}
			if (counter) candidate += to_string(counter);
			res.push_back(candidate);
		}	
		return res;
	}
};
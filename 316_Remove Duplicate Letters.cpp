class Solution {
public:
	string removeDuplicateLetters(string s) {
        if (s.length() < 2) return s;
		vector<int> dict (26, 0);
		vector<int> visited (26, 0);
		
        for (char c:s)
			dict[c-'a'] ++;

		string res;
		for (char curc:s) {
			int index = curc-'a';
			dict[index] --;
			if (visited[index])
				continue;

			while (res.length() && curc < res.back() && dict[res.back()-'a']) {
				visited[res.back()-'a'] = 0;
				res.pop_back();
			}
			res += curc;
			visited[index] = 1;
		}

		return res;
	}
};

/* the idea: Stack(thought) + hashmap(thought). We first count the appearance times of each
 * character in the string. Then we need a visited map to determine wheter a char has already
 * be visisted, which means up to our current position i (exclude), the target char has been
 * placed into the res string satisfying the smallest lexicographical order.
 * The process: for each char in string: first decrease the appearance times in hash-map, then
 * we go check if the char has already be visited, if so we skip to next character. Otherwise,
 * we use the stack thought, go check if the last char in res is larger than our current visited
 * one, if so and the hash-map shows that char has more counts than 1, then 
 * we pop the back char and reset it's visited status to 0, finally we just append the char to
 * the end of target and set the visited status to 1;
 * Go throught all char in string and then we are done 
 */
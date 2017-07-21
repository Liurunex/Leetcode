class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int p1 = -1, p2 = -1, res = INT_MAX;
		for (int i = 0; i < words.size(); ++ i) {
			if (words[i] == word1) p1 = i;
			else if (words[i] == word2) p2 = i;
			else continue;

			if (p1 >= 0 && p2 >= 0) {
				cout << p1 << " " << p2 << endl;
				res = min(res, abs(p1-p2));
			}
		}    
		return res;
	}
};
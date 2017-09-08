class Solution {
public:
	vector<string> generatePossibleNextMoves(string s) {
		vector<string> res;
		for (int i = 1; i < s.length(); ++ i) {
			if (s[i-1] == s[i] && s[i] == '+')
				res.push_back(s.substr(0, i-1) + "--" + s.substr(i+1));
		}
		return res;
	}
};
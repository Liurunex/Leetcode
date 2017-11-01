class Solution {
public:
	bool validWordSquare(vector<string>& words) {
		if (words.size() != words[0].size()) return false;
		for (int i = 0; i < words.size(); ++ i) {
			for (int j = 0; j < words[i].size(); ++ j) {
				if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i])
					return false;
			}
		}
		return true;
	}
};
/* the idae: intuitive idea: just simulate the process, the only thing need to be
 * considered is the column word "validation" where we should check j < words.size()
 * and then i < words[j].size()
 */
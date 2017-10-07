class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size()) return "";
		string res;
		for (int i = 0; i < strs[0].length(); ++ i) {
			int cur = strs[0][i];
			for (int j = 1; j < strs.size(); ++ j) {
				if (i >= strs[j].size() && strs[j].at(i) != cur)
					return res;
			}
			res += cur;
		}
		return res;
	}
};
/* NOTICE the out of range case
 */

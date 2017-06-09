class Solution {
public:
	int firstUniqChar(string s) {
	    if (s.size() == 0) return -1;
		unordered_map<char, vector<int>> dic;
		for (int i = 0; i < s.size(); ++ i) {
			if (dic.find(s[i]) == dic.end()) {
				vector<int> tem;
				tem.push_back(i);
				dic[s[i]] = tem;
			}
			else dic[s[i]].push_back(i);
		}
		int res = INT_MAX;
		for (auto i = dic.begin(); i != dic.end(); ++ i)
			if (i->second.size() == 1)
				res = min(res, i->second.back());

		if (res == INT_MAX) return -1;
		return res;
	}
};

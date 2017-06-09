class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> dic;
		vector<vector<string>> res;
		int i = 0;
		string tem;
		for (i = 0; i < (int)strs.size(); i++) {
			tem = strs[i];
			sort(tem.begin(), tem.end());
			if (!dic.count(tem)) {
				vector<string> addone;
				addone.push_back(strs[i]);
				dic[tem] = addone;
			}
			else
				dic[tem].push_back(strs[i]);
			tem.clear();
		}

		map<string, vector<string>>::iterator  iter;
		for (iter = dic.begin(); iter != dic.end(); iter++) 
			res.push_back(iter->second);
		return res;
	}
};
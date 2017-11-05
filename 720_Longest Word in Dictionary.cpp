class Solution {
public:
	string longestWord(vector<string>& words) {
        if (!words.size()) return "";
		unordered_set<string> dict;
		for (string word:words)
			dict.insert(word);
		string res;
		for (string word:words) {
			bool inside = true;
			for (int i = 0; i < word.length(); i ++) {
				string sub = word.substr(0, i+1);
				if (!dict.count(sub)) {
					inside = false;
					break;
				}
			}
			if (inside){
				if(res.length() < word.length() ||
					(res.length() == word.length() && word < res))
					res = word;
			}
		}
		return res;
	}
};
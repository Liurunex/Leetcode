class Solution {
public:
	int maxProduct(vector<string>& words) {
		sort(words.begin(), words.end(), [](string a, string b) -> bool {
			if (a.length() == b.length()) return a < b;
			else return a.length() > b.length();
		});
		vector<int> worddic (words.size(), 0);
		int res = INT_MIN;
		for (int i = words.size()-1; i >= 0; -- i) {
			for (char cc:words[i])
				worddic[i] |= 1 << (cc - 'a');
			for (int j = i; j < words.size(); ++ j) {
				if (words[i] == words[j])
					continue;
				if (!(worddic[j] & worddic[i])) {
					res = max(res, (int)(words[i].length()*words[j].length()));
                    //cout << words[i] << " * " << words[j] << endl;
					break;
				}
			}
		}
		return res == INT_MIN ? 0:res;
	}
};
/* the idea: Brute force + sort + word convert bit. Our idea is to sort the words list
 * based on length and then alphabet order in desending order. As a result, we first
 * select the candiate, then check from the candiate to the end of the list, the first
 * one we meet not sharing common letters is the largest product we can make in this
 * candiate. The key part is: how to judege if two string sharing letters, our method
 * is to transfer the word into a 26-digit intger, that is each digit represet the 
 * character, so that if two string sharing any letter, the & opeartion will produce
 * not 0!
 */

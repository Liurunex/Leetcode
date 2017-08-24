/* slow solution */
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};
		vector<string> alldic, res;
		for (size_t i = 0; i < digits.length(); ++ i) {
			if (digits[i] == '0' || digits[i] == '1') return {};
			alldic.push_back(findthedic(digits[i]));
		}
		findall(res, alldic, 0, alldic.size(), "");
		return res;
	}

	string findthedic(char c) {
		switch (c) {
			case '2': return "abc";
			case '3': return "def";
			case '4': return "ghi";
			case '5': return "jkl";
			case '6': return "mno";
			case '7': return "pqrs";
			case '8': return "tuv";
			case '9': return "wxyz";
		}
	}

	void findall(vector<string> &res, vector<string> dic, int index, int len, 
		string candiate) {
		if (index == len) {
			res.push_back(candiate);
			return;
		}

		for (size_t i = 0; i < dic[index].length(); ++ i) {
			string candiate_1 = candiate + dic[index].at(i);
			findall(res, dic, index+1, len, candiate_1);
		}
	}
};

/* better after using reference passing */
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};
		static vector<string> alldic = {"", "", "abc", "def", "ghi", "jkl", 
		"mno", "pqrs", "tuv", "wxyz"};
		string candiate (digits.length(), '\0');
		vector<string> res;
		findall(res, alldic, digits, 0, candiate);
		return res;
	}

	void findall(vector<string> &res, vector<string> alldic, string &digits, 
		int index, string &candiate) {
		if (index == digits.length()) {
			res.push_back(candiate);
			return;
		}
		string append = alldic[digits[index]-'0'];
		for (size_t i = 0; i < append.length(); ++ i) {
			candiate[index] = append[i];
			findall(res, alldic, digits, index+1, candiate);
		}
	}
};










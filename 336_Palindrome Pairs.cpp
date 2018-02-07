class Solution {
public:
	bool palinValid(string& str, int start, int end) {
		while (start < end) {
			if (str[start ++] != str[end --])
				return false;
		}
		return true;
	}

	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> dict;
		vector<vector<int>> res;
		set<int> sortedLen;
 		for (int i = 0; i< words.size(); ++ i) {
 			sortedLen.insert(words[i].size());
			dict[words[i]] = i;
 		}

		for (int i = 0; i < words.size(); ++ i) {
			string str = words[i];
			int n = str.size();
			reverse(str.begin(), str.end());
			// case: size equal
			if (dict.count(str) && words[i] != str)
				res.push_back({i, dict[str]});
			// case: size not equal
			auto endpoint = sortedLen.find(n);
			for (auto itr = sortedLen.begin(); itr != endpoint; ++ itr) {
				int len = *itr;
				// candidate + A case, here candidate is not reversed
				if (palinValid(str, 0, n-len-1) && dict.count(str.substr(n-len, len)))
					res.push_back({i, dict[str.substr(n-len, len)]});
				// A + candidate case:
				if (palinValid(str, len, n-1) && dict.count(str.substr(0, len)))
					res.push_back({dict[str.substr(0, len)], i});
			}
		}
		return res;
	}
};

/* the idea: Hash Table + String. intead of brute force, 我们hash table 来预存每一个string，
 * 同时把string的size 按照大小sort. 然后开始流程：取出每一string，先把它reverse了：
 * case 1: 当前string和他的reverse行车palindrome, 只需要检查hash map里面有没有reverse，同时reverse不能string相同
 * case 2: 当前string和小于其size的string组成palindrome：不需要考虑大size 的: 此时此前存好的sorted size就有用了，
 * 遍历存在的小size, 两种case: A + candidate = palindrome | candidate + A = palindrome, 都一样的分析：
 * 对于 A + candidate, 先判断candidate[0..n-A.size()-1]是不是palindrome，也就是reverse[A.size()..n-1]是不是palindrome，
 * 然后再去找reverse剩下的部分在不在hash map 里面！
 * */
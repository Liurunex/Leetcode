class Solution {
private:
	static bool comparator (int i, int j) { return (i > j); }

public:

	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> diction;
		for (int i = 0; i < tasks.size(); ++ i)
			diction[tasks[i]] ++;
		
		vector<int> sorteddic;
		for (auto iter = diction.begin(); iter != diction.end(); iter ++)
			sorteddic.push_back(iter->second);
		
		sort(sorteddic.begin(), sorteddic.end(), comparator);
		for (int i = 0; i < sorteddic.size(); ++ i)
			cout << "sorteddic: " << sorteddic[i] << endl;

		int res = 0;
		
		while (!sorteddic.empty()) {
			sort(sorteddic.begin(), sorteddic.end(), comparator);
			auto iter = sorteddic.begin();
			int out = 0;
			while (*iter != 0) {
				auto i = iter;
				for (int j = 0; j <= n; ++ j) {
					if (i == sorteddic.end()) {
						if (sorteddic.size() == 1 && !(*iter))
							break; 
						res += n - j + 1;
						break;
					}
					*i  -= 1;
					res += 1;
					if (*i == 0) {
						if (i == iter) { i++; continue; }
						sorteddic.erase(i);
					}
					else i ++;
				}
			}
			sorteddic.erase(iter);
		}
        return res;
	}
};


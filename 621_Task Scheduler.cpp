class Solution {
private:
	static bool comparator (int i, int j) { return (i >= j); }

public:

	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> diction;
		for (int i = 0; i < tasks.size(); ++ i) {
			if (diction.find(tasks[i]) != diction.end())
				diction[tasks[i]] ++;
			else diction[tasks[i]] = 1;
		}
		
		vector<int> sorteddic;
		for (auto iter = diction.begin(); iter != diction.end(); iter ++)
			sorteddic.push_back(iter->second);

		int res = 0, skip = 0;
		
		while (!sorteddic.empty()) {
			sort(sorteddic.begin(), sorteddic.end(), comparator);
			auto iter = sorteddic.begin();
			while (*iter > 0) {
				auto i = iter;
				for (int j = 0; j < n; ++ i, ++ j) {
					
					if (skip) { skip --; res ++; continue; }
					if (i == sorteddic.end()) {
						res ++;
						skip = n - j;
						continue;
					}
					auto cur = i;
					*cur --;
					res ++;
					if (*cur == 0) {
						sorteddic.erase(cur);
						if (sorteddic.empty()) break;
					}
				}
			}
		}
        return res;
	}
};
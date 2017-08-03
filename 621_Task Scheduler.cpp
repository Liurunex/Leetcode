class Solution {
private:
	bool comparator (pair<char, int> i, pair<char, int> j) { return (i.second >= j.second); }

public:

	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> diction;
		for (int i = 0; i < tasks.size(); ++ i) {
			if (diction.find(tasks[i]) != diction.end())
				diction[tasks[i]] ++;
			else diction[tasks[i]] = 1;
		}
		sort(diction.begin(), diction.end(), comparator);

		int res = 0, counter = 0;
		queue<int> window;
		
		while (1) {
			auto iter = diction.begin();
			int round = iter->second;
			auto iter_end = iter + n;
			while (iter != iter_end) {
				iter->second -= round;
				if (iter->second < 0) {
					auto rinforce = iter_end;
					diction.erase(iter);
				}
				iter ++;
			}
		}

	}
};
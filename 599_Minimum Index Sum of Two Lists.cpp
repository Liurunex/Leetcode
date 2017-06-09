class Solution {
public:
	struct mycompare {
	bool operator() (pair<int, string> const& a, pair<int, string> const& b) const {
		return a.first > b.first;
	}
};
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		vector<string> res;
		if (list1.size() == 1) {
			res.push_back(list1[0]);
			return res;
		}
		if (list2.size() == 1) {
			res.push_back(list2[0]);
			return res;
		}

		unordered_map<string, int> all;
		priority_queue<pair<int, string>, vector<pair<int, string>>, mycompare> common;

		for (int i = 0; i < list1.size(); ++ i)
			all[list1[i]] = i;
		for (int i = 0; i < list2.size(); ++ i)
			if (all.find(list2[i]) != all.end())
				common.push(make_pair(all[list2[i]] + i, list2[i]));

		int target_index = common.top().first;
		while (1) {
			if (common.size() == 0) break;
			pair<int, string> candiate = common.top();
			if (candiate.first == target_index) {
				common.pop();
				res.push_back(candiate.second);
			}
			else break;
		}
		return res;
	}
};

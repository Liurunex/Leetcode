class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		if (candies.size() == 0) return 0;
		int sisterGet = 0;
		set<int> sisterKind;
		unordered_map<int, int> candyDic;
		for (int i = 0; i < candies.size(); ++ i) {
			if (candyDic.find(candies[i]) == candyDic.end())
				candyDic[candies[i]] = 1;
			candyDic[candies[i]] ++;
		}

		for (auto i = candyDic.begin(); i != candyDic.end(); ++ i) {
			if (sisterGet == candies.size()/2) break;
			if (i->second == 0) continue;
			sisterGet ++;
			i->second --;
			sisterKind.insert(i->first); 
		}
		return sisterKind.size();
	}
};

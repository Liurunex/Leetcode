class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> countDic;
		for (int i = 0; i < nums.size(); ++ i) {
			if (countDic.find(nums[i]) != countDic.end())
				countDic[nums[i]] ++;
			else countDic[nums[i]] = 1;
		}

		vector<vector<int>> resDic(nums.size(), vector<int>());
		for (pair<int, int> item : countDic) 
			resDic[item.second - 1].push_back(item.first);
		
		int countK = 0;
		vector<int> returnVector;
		for (int i = resDic.size()-1; i >= 0; -- i) {
			if (!resDic[i].empty()) {
				for (int j = 0; j < resDic[i].size(); ++ j) {
					returnVector.push_back(resDic[i][j]);
					countK ++;
					if (countK == k)
						return returnVector; 
				}
			}
		}
		return returnVector;
	}
};

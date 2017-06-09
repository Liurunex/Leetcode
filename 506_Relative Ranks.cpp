class Solution {
public:
	struct mycompare {
		bool operator() (pair<int, int> const& a, pair<int, int> const& b) const {
			return a.second < b.second;
		}
	};

    vector<string> findRelativeRanks(vector<int>& nums) {
    	priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> dic;
    	vector<string> res (nums.size(), "");
    	int count = 0;
    	for (int i = 0; i < nums.size(); i++) 
    		dic.push(make_pair(i, nums[i]));
   		while (!dic.empty()) {
   			count ++;
   			switch(count) {
   				case 1: 
   					res[dic.top().first] = "Gold Medal"; dic.pop(); break;
   				case 2:
   					res[dic.top().first] = "Silver Medal"; dic.pop(); break;
   				case 3:
   					res[dic.top().first] = "Bronze Medal"; dic.pop(); break;
   				default:
   					res[dic.top().first] = to_string(count); dic.pop(); break;
   			}
   		}
   		return res;
    }
};
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map<int, int> diffmap;
		diffmap[0] = -1;
		int res = 0, zeros = 0, ones = 0;
		for (int i = 0; i < nums.size(); ++ i) {
			if (nums[i]) ones ++;
			else zeros ++;
			int diff = ones - zeros;
			if (diffmap.find(diff) != diffmap.end())
				res = max(res, i - diffmap[diff]);
			else diffmap[diff] = i;
		}
		return res;
	}
};

/*
the idea: we use diff to record num(1) - num(0), and hashtable to project diff to index, the 
thought is simple, cumulative mehod works here: we go through the array, compute diff at each 
index from index 0 to current index, we project this diff to index in hashmap, once we find the
diff which is key has already existed in map, then we just find a candiate i-map[diff];

the trick: we must add {0, -1} into map, otherwise we get wrong in case the result is started at index 0
 */}

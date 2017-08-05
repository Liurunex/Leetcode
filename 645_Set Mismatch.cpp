class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		unordered_map<int, int> diction;
		vector<int> res;	
		for (int i = 0; i < nums.size(); ++ i)
			diction[i+1] = 1;
		for (int i = 0; i < nums.size(); ++ i) {
			diction[nums[i]] -= 1;
			if (diction[nums[i]] < 0)
				res.push_back(nums[i]);
		}
		for (int i = 0; i < nums.size(); ++ i)
			if (diction[i+1] == 1)
				res.push_back(i+1);
		return res;	
	}
};

/*
a better idea of change original vector to ascending 
vector<int> findErrorNums(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            while(nums[i] != nums[nums[i] - 1])swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] != i + 1)return {nums[i], i + 1};
        }
    }
 */
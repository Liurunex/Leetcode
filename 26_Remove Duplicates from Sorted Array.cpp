class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int index = 0;
		for (auto item:nums)
			if (!index || item != nums[index-1])
				nums[index ++] = item;
		return index;
	}
};
/*
more effective than origianl two pointer method, use the index-1 and index
to record current and previous item, if duplicate, index stay same and move to
item so that the index will always equal to the non-duplicate array length
 */
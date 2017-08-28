class Solution {
public:
	int pathSum(vector<int>& nums) {
        if (!nums.size()) return 0;
		vector<unordered_map<int, int>> level;
        unordered_map<int, int> initial;
        initial[1] = nums[0]%10;
		level.push_back(initial);
        int clevel = 1;
		for (size_t i = 1; i < nums.size(); ++ i) {
			if (clevel != nums[i]/100) {
				unordered_map<int, int> newlevel;
				newlevel[(nums[i]/10)%10] = nums[i]%10;
                level.push_back(newlevel);
				clevel ++;
				continue;
			}
			level.back()[(nums[i]/10)%10] = nums[i]%10;
		}
        return calculate(0, level, 1, 1, nums.back()/100);
	}

	int calculate(int pres, vector<unordered_map<int, int>> &level, int clevel, int corder, int limit) {
        int res = pres + level[clevel-1].at(corder)%10;
        int left = 0, right = 0, left_empty = 0, right_empty = 0;
        if (clevel < limit && level[clevel].find(2*corder-1) != level[clevel].end())
            left = calculate(res, level, clevel+1, 2*corder-1, limit);
        else left_empty = 1;

        if (clevel < limit && level[clevel].find(2*corder) != level[clevel].end())
            right = calculate(res, level, clevel+1, 2*corder, limit);
        else right_empty = 1;

        if (clevel >= limit || (left_empty && right_empty)) return res;
        return left + right;
	}
};
/*
to represent the tree, we convert the array to vector<map> to avoid extra space overhead, 
vector stores all tree nodes by level, map stores all nodes in same level by order;
the problem here is we need to determine if to return current res or left+right (one path or two),
the solution is to add mark in order to check left and right child respectively, once current node 
has no child, we need to return its current val, othervise return the sum of left and right
 */
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> sub;
        for (int i = 0; i < nums.size(); ++ i) {
            sub.push_back(nums[i]);
            dfs_helper(res, nums, sub, i);
            sub.pop_back();
        }
        vector<vector<int>> vres(res.begin(), res.end());
        return vres;
    }

    void dfs_helper(set<vector<int>> &res, vector<int>& nums, 
        vector<int> sub, int index) {     
        for (int i = index+1; i < nums.size(); ++ i) {
            if (nums[index] <= nums[i]) {
                sub.push_back(nums[i]);
                dfs_helper(res, nums, sub, i);
                sub.pop_back();
            }
        }
        if (sub.size() > 1)
            res.insert(sub);
    }
};
/* the idea: we just set each node as the start point and do dfs on each of them, keep a
 * sub vector to store the curent acceptable anwser; the trick is how to handle the 
 * duplicate cases, the inital way is to use set<vector> instead of vector<vector>>, and 
 * convert the set back vector just brefore returing the result.
 * THE BETTER WAY: we use a unordered_set to keep tracking the number we have used, that
 * is if we find the numebr has been added to the unordered_set already then we should skip
 * this case, since it has been counted in our sub results
 */
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        helper(nums, 0, sub, res);
        return res;
    }
    void helper(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& res) {
        if (sub.size() >= 2) res.push_back(sub);
        unordered_set<int> redredundant_filter;
        for (int i = start; i < nums.size(); ++i) {
            if (!sub.empty() && sub.back() > nums[i] 
                || redredundant_filter.count(nums[i])) continue;
            sub.push_back(nums[i]);
            redredundant_filter.insert(nums[i]);
            helper(nums, i+1, sub, res);
            sub.pop_back();
        }
    }
};

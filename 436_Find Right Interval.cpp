/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& intervals) {
		map<int, int> startmp;
		vector<int> res (intervals.size(), -1);
		for (int i = 0; i < intervals.size(); ++ i)
			startmp[intervals[i].start] = i;

		for (int i = 0; i < intervals.size(); ++ i) {
			auto iter = startmp.lower_bound(intervals[i].end);
			if (iter != startmp.end())
				res[i] = iter->second;
		}
        return res;
	}
};

/* the idea: Binary Search + Map. We use map to sort the interavals' starts while mapping
 * it to its index. We then iterate our intervals, using Binary Search to find the first
 * start that is equvalent or greater than our current end, Notice that map is tree-structured
 * so that we can directly use lower_bound to do our binary search to find the target.
 */

 */
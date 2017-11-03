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
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.size() < 2) return 0;
		sort(intervals.begin(), intervals.end(), [](Interval x, Interval y) -> bool {
			if (x.start != y.start) return x.start < y.start;
			return x.end < y.end;
		});
		int res = 0;
		int pre_end = intervals[0].end;
		for (int i = 1; i < intervals.size(); ++ i) {
            //cout << intervals[i].start << " " << intervals[i].end << "\n";
			if (intervals[i].start >= pre_end) {
				pre_end = intervals[i].end;
				continue;
			}
			res ++;
			pre_end = min(pre_end, intervals[i].end);
		}
		return res;
	}
};

/* the idea: greedy + sort, much simialr to meeting roow II and burst baloons: just
 * sort the intervals based its start position (if tie we consider end position order),
 * inital the previous end record as first interval's end, then we do our GREEDY iteration:
 * for interval i, two cases: if it started after the previous end, we are fine and no need
 * to delete any interval, but just update the previous end record to current intervals; in
 * other case: the current interval overlap with the previous one, we have delete one of them:
 * and this is where GREEDY taking place -> we keep the one with less range, and delete the one
 * with higer end boundary, why this? simple reason: we want to keep the confliction made by
 * current two intervals affecting less intervals in future, namely, lower end boundary decrese
 * the chances of conflictions of future intervals
 */
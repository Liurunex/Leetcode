class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto i = intervals.begin();
		int overlap = 0;
		while (i != intervals.end()) {
			if (newInterval.start > i->end) {
				/* go to next */
				i ++;
				continue;
			}
			else if (newInterval.end < i->start) {
				/* terminate */
				break;
			}
			else  {
				/* overlap, do merge() */
				newInterval.start = min(newInterval.start, i->start);
				newInterval.end = max(newInterval.end, i->end);
				overlap ++;
			}
		}
		if (overlap)
			i = intervals.erase(i-overlap, i);
		intervals.insert(i, newInterval);
		return intervals;
	}
};
/* the idea: Iteration thought. We iterate through whole intervals, comparing each interval
 * with the target, three cases:
 * if target.start > i->end means on overlap yet, and we should go to next interval
 * if target.end < i->start means we are done, no need to iterate next interval
 * otherwise, overlapping happen, and we have to merge the two intervals, NOTICE the above 
 * method is better that below one, where below one will immediately remove old overlapping
 * interval, which will cost O(n), as we might have many overlaps behind, the remove will be
 * O(n^2). Instead doing this, we just count how many overlap happends, and once we reach the
 * terminated condition, we erase a range those overlapping intervals, which will cost O(n), so 
 * that faster
 * */
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto i = intervals.begin();
		while (i != intervals.end()) {
			if (newInterval.start > i->end) {
				/* go to next */
				i ++;
				continue;
			}
			else if (newInterval.end < i->start) {
				/* terminate */
				break;
			}
			else  {
				/* overlap, do merge() */
				newInterval.start = min(newInterval.start, i->start);
				newInterval.end = max(newInterval.end, i->end);
				i = intervals.erase(i);
			}
		}
		intervals.insert(i, newInterval);
		return intervals;
	}
};
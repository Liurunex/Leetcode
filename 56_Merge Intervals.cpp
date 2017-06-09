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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return vector<Interval> {};
    	
    	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
    	vector<Interval> output;
    	vector<Interval>::iterator i = intervals.begin();
    	while(i != intervals.end()) {
    		if(output.empty())
    			output.push_back(*i);
    		else {
    			if(i->start > output.back().end)
    				output.push_back(*i);
    			else
    				output.back().end = max(i->end, output.back().end);
    		}
    		++ i;
    	}
    	return output;
    }
};
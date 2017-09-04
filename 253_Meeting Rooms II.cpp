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
	int minMeetingRooms(vector<Interval>& intervals) {
		vector<int> starthouse;
		vector<int> endhouse;

		for (Interval i:intervals) {
			starthouse.push_back(i.start);
			endhouse.push_back(i.end);
		}

		sort(starthouse.begin(), starthouse.end());
		sort(endhouse.begin(), endhouse.end());

		int rooms = 0, cur_meeting_end_index = 0;
		for (size_t i = 0; i < intervals.size(); ++ i) {
			if (starthouse[i] < endhouse[cur_meeting_end_index]) 
				rooms ++;
			else cur_meeting_end_index ++;
		}

		return rooms;
	}
};

/*
the idea: we must know both the start time and end time of all meetings, and 
place them on the time line for comapring; our method is we don't care which 
meeting is on and which meeting is comming for next; all we need to know is 
if the start time of next meeting is beyoung the end time of current end time 
on the time line. On the basis of that, we use two array to store all start time
and end time in ascending order respectively; set a index to track our current 
end time, go throught the start time array, if the next start time is beyoud 
current end time, we don't need extra room and move forward both index of two arrays
move forward; otherwise we need extra room and only move forward the start index
 */

/*
map solution: we stores both start time(wiht value ++) and end time(with value --)
go through the map, make rooms += map[i].value; res = max(res, rooms), finally return res
 */

/*
priority queue(min heap): we firstly sort intervals by start time, then build a
new priority queue(min heap) pq<int, vector<int>, greater<int>>, the pq stores all the 
runinng meeting end, that is the key use of heap; we go through the intervals,
if pq is not empty and current start time is beyound the current top() in pq 
(which is current minimun end time), we pop it; beside that, and in any other cases
inclduing pq is empty or start time is smaller than pq top element, we just push current end time;
once we go through the whole intervals, the size of pq is what we want
 */
class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points) {
        if (!points.size()) return 0;
		sort(points.begin(), points.end(), [](pair<int,int> X, pair<int,int> Y) -> bool{
			return X.first < Y.first;
		});

		int res = 1, arrow_catch = points[0].second;
		for (auto ballon:points) {
			if (ballon.first > arrow_catch) {
				res ++;
				arrow_catch = ballon.second;
			}
			else {
				arrow_catch = min(arrow_catch, ballon.second);
			}
		}
		return res;
	}
};
/* the idea: greedy -> local greedy to optimal: we first sort the points
 * based on their start point, then we set a arrow_catch which means the 
 * far most range the current shot can catch for ballons; we iterate the
 * sorted poitnes, first inital the arrow_num = 1 and arrow_catch = 
 * point[0].second, that is for the first ballon, we will shot one; then
 * go throught the poitns, using the greedy thougths: once the current
 * ballone start > the arrow_catch, that means we have to shot again,
 * update the arrow_catch to our current ballon end; otherwise if the 
 * current ballon start < arrow_catch, that means our previous shot
 * can catch current ballon since it overlap with our current arraow
 * range, in this case just update the arrow_catch to minium of its
 * current value and the end of curretn ballon;
 *
 * the thougths: it's kindly similar to the meeting room questions!
 * but priority queue cannot help here
 */ 


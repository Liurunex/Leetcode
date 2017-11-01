class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (!houses.size() && !heaters.size()) return 0;
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int hindex = 0, radius = 0;
		for (int i = 0; i < houses.size(); ++ i) {
			int curhouse = houses[i];
			while (hindex < heaters.size()-1 && 
				abs(heaters[hindex+1]-curhouse) <= abs(heaters[hindex]-curhouse))
				hindex ++;
			radius = max(radius, abs(heaters[hindex]-curhouse));
		}
		return radius;
	}
};
/* the idea: sort two vectors first, then we consider to cover a hourse, it will
 * either be covered by heater[j] or heater[j+1], there is totally three cases:
 * hourse is ahead to heater[j], which should be covered by heater[j]; hourse is in
 * the middle of heater[j] and j+1, which we should cover it with the closer heataer;
 * and the last case is hourse is behind the heater[j+1], which is clearly that j+1 heater
 * should cover it. On the basis of that, we iterate each hourse and determine which
 * heater to cover it. First set heater index to 0, for hourse i, once we find it is close
 * to heater j+1, we move to next heater and check again until the new heater j can 
 * cover the house i; after that we update our radius.
 * the trick: NOTICE even the hourse i has equal distance to the heater j and j+1, we should
 * move to j+1, otherwise some result will be wrong
 */

/* the Binary Search way is alomost same, the only difference is instead of using while loop
 * to find the heater to cover the house, we use BS to find the lower_bond of heaters for current
 * hourse, and then update the radius
 */

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (!houses.size() && !heaters.size()) return 0;
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int hindex = 0, radius = 0;
		for (int i = 0; i < houses.size(); ++ i) {
			int curhouse = houses[i];
			int left = hindex, right = heaters.size()-1;
			while (left <= right) {
				int mid = left + (right-left)/2;
				if (heaters[mid] < curhouse) left = mid+1;
				else right = mid-1;
			}
			int lower_heater = left;
			int distance_higher_heater = left == heaters.size() ? INT_MAX:abs(heaters[lower_heater]-curhouse);
			int distance_lower_heater  = left == 0 ? INT_MAX:abs(heaters[lower_heater-1]-curhouse);
			radius = max(radius, min(distance_lower_heater, distance_higher_heater));
		}
		return radius;
	}
};
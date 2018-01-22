class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> heights;
		for (auto building:buildings) {
			heights.push_back({building[0], -1*building[2]});
			heights.push_back({building[1], building[2]});
		}
		/* normaly ascending order of x-value, if equal, 
			for both left points, decending height order;
			for both right points, acending height order;
			for one right and one left, left goes first 
		*/
		sort(heights.begin(), heights.end(), [](pair<int, int> x, pair<int, int> y) {
			if (x.first == y.first)
				return x.second < y.second;
			return x.first < y.first;
		});

		vector<pair<int, int>> res;
		// record the previous visited heights of buildings which not yet ended
		priority_queue<int> preHights;
		// mark those heights need to be deleted from pq
		unordered_map<int, int> deleteHeight;
    	int cur = 0, pre = 0;
        /* for the case where we reach the ground */
		preHights.push(0);

		for (auto pos:heights) {
			// meet with building left start, do insersion of pq
			if (pos.second < 0)
				preHights.push(abs(pos.second));
			// meet with building right end, do deletion of this particular height
			else {
				deleteHeight[pos.second] ++;
				while (preHights.size() && (deleteHeight.count(preHights.top()) 
					&& deleteHeight[preHights.top()] > 0)) {
					deleteHeight[preHights.top()] --;
					preHights.pop();
				}
			}
			// comparing current heighest height with previous one, if differ, means a key point!
			cur = preHights.top();
			if (pre != cur)
				res.push_back({pos.first, cur});
			pre = cur;
		}
		return res;
	}
};	

/* the idea: Heap(Priority Queue). We first stored all buidlings by its x-val and heights, since we want to 
 * iterate all points to determine the key point: left endpoint of a horizontal line segment. To sort the new
 * iterating vector, we should be awared that: normaly ascending order of x-value, if equal: 
 * for both left points, decending height order, since first check smaller height one will produce wrong key point;
 * for both right points, acending height order, since first check larger height will remove the larger height 
 * first so that produce wrong key point;
 * for one right and one left, left goes first, otherwise produced wrong key point.
 * The second thing is to iterate the vector, we use a max-heap to stores all heights we current meet, the cur and pre
 * denote the highest height of previous and current states. 
 * By itearting, if we meet with left point, just insert the height into heap; if meet with right point, we should remove
 * that particular height from heap. In both case, we will update cur to heap.top(), if cur != pre, it indicating there is 
 * a key point (current x-val, cur). Travel all points and we are done.
 * Trick 1: to differ left and right points of a building, we assigne -1*height to left, height to right, this is a clever way
 * to complete our sort process without complicate logic judegment!
 * Trick 2: heap doesn't provide erase fucntion, so that we have a hash-map to denote the status of heights, everytime when
 * removing from heap, we go check the hashmap[heap.top()] > 0, then keep pop until not satifying rules.
 * Trick 3: instead of using heap, we can use multiset which is sorted by key and allowing duplicate keys, see below short solution
 */

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> heights;
		for (auto building:buildings) {
			heights.push_back({building[0], -1*building[2]});
			heights.push_back({building[1], building[2]});
		}
		sort(heights.begin(), heights.end(), [](pair<int, int> x, pair<int, int> y) {
			if (x.first == y.first)
				return x.second < y.second;
			return x.first < y.first;
		});

		vector<pair<int, int>> res;
		multiset<int> preHights;
    	int cur = 0, pre = 0;
		preHights.insert(0);

		for (auto pos:heights) {
			if (pos.second < 0)
				preHights.insert(abs(pos.second));
			else
				preHights.erase(preHights.find(pos.second));
			
			cur = *(preHights.rbegin());
			if (pre != cur)
				res.push_back({pos.first, cur});
			pre = cur;
		}
		return res;
	}
};	
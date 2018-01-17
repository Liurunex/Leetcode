class Solution {
public:
	bool isReflected(vector<pair<int, int>>& points) {
		int xmin = INT_MAX, xmax = INT_MIN;
		unordered_map<int, unordered_set<int>> storage;

		for (auto point:points) {
			xmin = min(xmin, point.first);
			xmax = max(xmax, point.first);

			storage[point.first].insert(point.second);
		}

		double yline = xmin + ((double)(xmax-xmin))/2;

		for (auto point:points) {
			int reflect = 2*yline - point.first;

			if (storage.count(reflect) && storage[reflect].count(point.second))
				continue;
			return false;
		}
		return true;
	}
};

/* the idea: hash-map: we first calculate median of all x-index which is the divided line.
 * So that we go through all points, find the max and min. Also we need a hash-map to
 * mapping the x-index to all existed y-index, which is usedful in second round traversal
 * to check each point to find out if there existed a refelect */
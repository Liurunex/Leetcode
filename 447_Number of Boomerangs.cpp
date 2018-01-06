class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int res = 0;
		for (int i = 0; i < points.size(); ++ i) {
			unordered_map<long, int> distancemap;
			for (int j = 0; j < points.size(); ++ j) {
				if (i == j) continue;
				long distance = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
				distancemap[distance] ++;
			}
			for (auto it = distancemap.begin(); it != distancemap.end(); ++ it)   
                res += it->second * (it->second-1);
		}
		return res;
	}
};

/* the idea: iterate each number, view it as the midpoint, use hashmaps to stores all distances from other points and
 * corresponding counts, finally count the possible tuples.
 * NOTICE: ^ in c++ is bit opeartion, not pow!!! Your should always use pow fucntion to calculate power
 */
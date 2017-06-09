class Solution {
public:
	int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
		vector<int> squToNut(nuts.size(), -1), treeTpNut(nuts.size(), -1);
		pair<int, int> first = make_pair(-1, INT_MAX);
		for (int i = 0; i < nuts.size(); ++ i) {
			squToNut[i] = abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]);
			treeTpNut[i] = abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]);
			if (first.second > squToNut[i] - treeTpNut[i]) {
				first.first = i;
				first.second = squToNut[i] - treeTpNut[i];
			}
		}

		int distance = 0;
		cout << first.first << endl;
		for (int i = 0; i < nuts.size(); ++ i) {
			if (i == first.first)
				distance += treeTpNut[i] + squToNut[i];
			else
				distance += 2*treeTpNut[i];
		}
		return distance;
	}
};

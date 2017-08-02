class Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		int res = 0;
		unordered_map<int, int> colcandicate;
		for (int i = 0; i < picture.size(); ++ i) {
			int bcount = 0, colpos = -1;
			for (int j = 0; j < picture[0].size(); ++ j) {
				if (bcount > 1) { 
					colpos = -1;
					continue;
				}
				if (picture[i][j] == 'B') {
					bcount ++;
					colpos = j;
				}
			}
			if (colpos != -1) {
				if (colcandicate.find(colpos) == colcandicate.end())
					colcandicate[colpos] = 1;
				else colcandicate.erase(colpos);
			}
		}

		for (auto j = colcandicate.begin(); j != colcandicate.end(); ++ j) {
			int bcount = 0;
			for (int i = 0; i < picture.size(); ++ i) {
				if (bcount > 1) 
					continue;
				if (picture[i][j->first] == 'B')
					bcount ++;
			}
			if (bcount == 1) res ++;
		}
		return res;
	}
};
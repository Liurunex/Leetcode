class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
		pair<int ,int> median = {0,0};
		vector<int> people_row;
		vector<int> people_col;
		int thesize = 0;
		for (int i = 0; i < grid.size(); ++ i) {
			for (int j = 0; j < grid[0].size(); ++ j) {
				if (grid[i][j]) {
					people_row.push_back(i);
					people_col.push_back(j);
					thesize ++;
				}
			}
		}
        int res = 0;
		nth_element(people_row.begin(), people_row.begin()+thesize/2, people_row.end());
		nth_element(people_col.begin(), people_col.begin()+thesize/2, people_col.end());
		median.first  = people_row[thesize/2];
		median.second = people_col[thesize/2];
		for (int i = 0; i < thesize; ++ i) {
			res += abs(people_row[i] - median.first) +
			abs(people_col[i] - median.second);
		}
		return res;
	}
};
/* the idea: simple, just find the median points among all people
 * positions and we are done
 */

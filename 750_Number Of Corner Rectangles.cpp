class Solution {
public:
	int countCornerRectangles(vector<vector<int>>& grid) {
		int res = 0;
		unordered_map<int, unordered_map<int, int>> comb;
		for (int i = 0; i < grid.size(); ++ i) {
			for (int j = 0; j < grid[0].size(); ++ j) {
				for (int k = j+1; k < grid[0].size(); ++ k) {
					if (grid[i][j] && grid[i][k]) {
						if (comb.count(j) && comb[j].count(k))
							res += comb[j][k];
						comb[j][k] ++;
					}
				}
			}
		}
		return res;	
	}
};

/* the idea: Combination. We handle a nested hash-map which mapping the index
 * of 1 position to another 1 postion with its appearing times, where both
 * 1 positions are in the same line. Thus we iterate each line, find all combinations
 * of 1s in this line, go check if we already have the same in preivous lines, which is
 * stored n our nested hash-map, then calculate how many rectangles formed here, finaly
 * just increase teh combination counter at corresponding hash-value
 * */
/* below is the method requres no extra space, it fixed the coloumns and iterate the rows*/
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = 0;
        for (int left = 0; left < n - 1; ++left) {
            for (int right = left + 1; right < n; ++right) {
                int count = 0;
                for (int i = 0; i < m; ++i) {
                    if (grid[i][left] == 1 && grid[i][right] == 1) {
                        count += 1;
                    }
                }
                result += count * (count - 1) / 2;
            }
        }
        return result;
    }
};
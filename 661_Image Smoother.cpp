class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		if (M.empty()) return {};
		vector<vector<int>> res (M.size(), vector<int>(M[0].size(), 0));
		vector<pair<int, int>> dictions{{0,-1}, {0,1}, {1,0}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
		for (int i = 0; i < M.size(); ++ i) {
			for (int j = 0; j < M[0].size(); ++ j) {
				int sum   = M[i][j];
				int count = 1;
				for (auto dic: dictions) {
					int nx = i+dic.first;
					int ny = j+dic.second;
					if (nx >= 0 && nx < M.size() && ny >= 0 && ny < M[0].size()) {
						sum += M[nx][ny];
						count ++;
					}
					res[i][j] = sum/count;
				}
			}
		}
		return res;
	}
};
/* the idea: simulate idea, only notice to use directions vector
 * /
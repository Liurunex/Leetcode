class Solution {
public:
	double knightProbability(int N, int K, int r, int c) {
		if (!K) return 1;
		vector<pair<int, int>> action = {{-2,1}, {-2,-1}, {-1,2},{-1,-2}, {1,2}, {1,-2}, {2,1}, {2,-1}};
		double onboard = 0, offboard = 0;
		for (int i = 0; i < action.size(); ++ i) {
			goknight_bfs(N, K-1, r+action[i].first, c+action[i].second, 
				onboard, offboard, action);
		}
		cout << onboard <<  " off: " << pow(8,K) << endl;
		return (double)onboard/pow(8,K);
	}

	void goknight_bfs(int& N, int step, int r, int c, 
		double& onboard, double& offboard, vector<pair<int, int>>& action) {
		if (r >= N || r < 0 || c >= N || c < 0) {
			offboard += 1;
			return;
		}
		if (!step) {
			onboard += 1;
			return;
		}

		for (int i = 0; i < action.size(); ++ i) {
			goknight_bfs(N, step-1, r+action[i].first, c+action[i].second, 
				onboard, offboard, action);
		}
	}
};
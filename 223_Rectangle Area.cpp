class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		if (B >= H || F >= D || E >= C || A >= G) return (C-A)*(D-B) + (G-E)*(H-F);
		vector<int> xAxis {A, C, E, G};
		vector<int> yAxis {B, D, H, F};
		sort(xAxis.begin(), xAxis.end());
		sort(yAxis.begin(), yAxis.end());

		return (C-A)*(D-B)+(G-E)*(H-F) - (xAxis[2]-xAxis[1])*(yAxis[2]-yAxis[1]);
		
    }
};

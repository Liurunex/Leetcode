class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		if (!costs.size()) return 0;
		int r_select = 0, g_select = 0, b_select = 0;
		for (int i = 0; i < costs.size(); ++ i) {
			int previous_r = r_select, previous_g = g_select, previous_b = b_select;
			r_select = costs[i][0] + min(previous_g, previous_b);
			b_select = costs[i][1] + min(previous_r, previous_g);
			g_select = costs[i][2] + min(previous_r, previous_b);
		}
		return min(r_select, min(g_select, b_select));
	}
};

/*  the idea actually is part greedy to whole optimize 
	make the r_select as the total cost of current house patinting red;
	for house n:
		if choose red, the currnet total cost will be:
		r_sum = cost[n][red] + min(sum of previous house green , sum of previous house blue)
		update the sum of last hourse red to r_sum in next loop, 
		since our current hourse is the previous hourse in next loop; 
		then forward to next house 
	do this for all three choices
*/
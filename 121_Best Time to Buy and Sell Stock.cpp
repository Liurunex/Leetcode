class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int temMin = prices[0], res = 0;
        for (int i = 0; i < prices.size(); i++) {
        	temMin = min(prices[i], temMin);
        	res = max(res, prices[i] - temMin);
        }
        return res;
    }
};
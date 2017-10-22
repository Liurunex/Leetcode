class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
		vector<int> noStack (prices.size(), 0);
		vector<int> ownStack (prices.size(), 0);
		ownStack[0] = -prices[0];
		for (int i = 1; i < prices.size(); ++ i) {
			noStack[i] = max(noStack[i-1], ownStack[i-1]+prices[i]-fee);
			ownStack[i] = max(ownStack[i-1], noStack[i-1]-prices[i]);
		}
		return noStack[prices.size()-1];
	}
};
/* the idea: similar to buy stock with cooldown, what we do is to 
 * set two dp table: hold or non-hold stock;
 * the trick: notice the transaction fee only count once for a buy-sell
 * process!
 */

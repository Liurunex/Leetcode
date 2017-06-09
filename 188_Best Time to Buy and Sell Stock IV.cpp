/*
有个坑，就是如果k的值远大于prices的天数，比如k是好几百万，而prices的天数就为若干天的话,
上面的DP解法就非常的没有效率，应该直接用Best Time to Buy and Sell Stock II 买股票的最佳时间之二的方法来求解

*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        
          if (k >= prices.size() / 2) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
        
      vector<vector<int>> atDay (k+1, vector<int> (prices.size(), 0));
      vector<vector<int>> period (k+1, vector<int> (prices.size(), 0));
        
        for (int j = 1; j < k+1 ; j ++) {
            for (int i = 1; i < prices.size(); i ++) {
            
              atDay[j][i] = max(period[j-1][i-1] + max(0, prices[i] - prices[i-1]),
              atDay[j][i-1] + prices[i] - prices[i-1]);    
              
              period[j][i] = max(period[j][i-1], atDay[j][i]);
            }
        }
      return period[k][prices.size()-1];
    }
};
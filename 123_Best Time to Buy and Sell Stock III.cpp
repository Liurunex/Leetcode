class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
    	int k = 2;
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

/*
http://blog.csdn.net/linhuanmars/article/details/23236995


local[i][j] = 
max(
global[i-1][j-1] + max(diff,0), 
local[i-1][j] + diff
)，

*/
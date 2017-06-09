/*** TLE ***
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() < 2) return 0;
        vector<int> sell (prices.size(), 0);
        sell[0] = 0; 
        sell[1] = (prices[1]-prices[0])>0 ? (prices[1]-prices[0]):0;
        sell[2] =  max(0, max(prices[2]-prices[1], prices[2]-prices[0]));
        for (int i = 3; i < prices.size(); i ++) {
        	for (int j = -1; j < i-1; j ++) {
        		if (j < 0) {
        			for (int k = 0; k <= i; k++) 
        				sell[i]= max(sell[i], prices[i] - prices[k]);
        		}
        		else {
        			for (int k = j+2; k <= i; k++) 
        				sell[i]= max(sell[i], sell[j] + prices[i] - prices[k]);
        		}	
        	}	
        }
        int res = 0;
        for (int i = 0; i < sell.size(); i++) {
        	res = max(res, sell[i]);
        	cout << sell[i] << endl;
        }
        return res;
    }
};
/*** TLE ***/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() < 2) return 0;
        vector<int> noStack (prices.size(), 0);
        vector<int> ownStack (prices.size(), 0);

        noStack[0] = 0;
        ownStack[0] = -prices[0];
        noStack[1] = (prices[1]-prices[0])>0 ? (prices[1]-prices[0]):0;
        ownStack[1] = max(-prices[0], -prices[1]);

        for (int i = 2; i < prices.size(); i ++) {
        	noStack[i] = max(noStack[i-1], ownStack[i-1]+prices[i]);
        	ownStack[i] = max(ownStack[i-1], noStack[i-2]-prices[i]);
        }
        
        return noStack[prices.size()-1];
    }
};














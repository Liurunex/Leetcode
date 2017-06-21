/* space O(all item)*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	if (triangle.size() == 1) return triangle[0][0];
 		vector<vector<int>> dp;
 		for (int i = 0; i < triangle.size(); ++ i) {
 			vector<int> addrow (triangle[i].size(), 0);
 			dp.push_back(addrow);
 		}      

 		for (int i = 0; i < triangle[triangle.size()-1].size(); ++ i)
 			dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];

 		for (int i = triangle.size()-2; i >= 0; -- i) 
 			for (int j = 0; j < triangle[i].size(); ++ j) 
 				dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
 		

 		return dp[0][0];
    }
};

/* space O(1)*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	if (triangle.size() == 1) return triangle[0][0];
    	
 		for (int i = triangle.size()-2; i >= 0; -- i) 
 			for (int j = 0; j < triangle[i].size(); ++ j) 
 				triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
 		

 		return triangle[0][0];
    }
};
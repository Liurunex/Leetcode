class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++ i) {
            vector<int> tem = vector<int> (i+1, 1);
            for (int j = 1; j < tem.size()-1; ++ j) {
                tem[j] = res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(tem);
        }
        return res;
    }
};
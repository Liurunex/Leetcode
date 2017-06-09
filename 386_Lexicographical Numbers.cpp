class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        helper(1, n, res);
        return res;
    }
    
    void helper(int target, int n, vector<int>& res) {
        if (target > n) return;
        res.push_back(target);
        helper(target * 10, n, res);
        if (target % 10 != 9) helper(target+1, n, res);
    }
};

/*
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int c = 0;
        for (c = 1; c < 10; c++) 
            DFS(c, n, res);
        return res;
    }

    void DFS(int i, int n, vector<int> & res) {
        int c = 0;
        if (i <= n) {
            res.push_back(i);
            for (c = 0; c < 10; c++)
                DFS(i*10 + c, n, res);
        }
    }

};
*/
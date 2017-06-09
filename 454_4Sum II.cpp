class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> ABmap;
        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < B.size(); j++) {
                if (ABmap.find(A[i] + B[j]) == ABmap.end())
                    ABmap[A[i] + B[j]] = 1;
                else ABmap[A[i] + B[j]] += 1; 
            }
        }

        for (int k = 0; k < C.size(); k ++) {
            for (int l = 0; l < D.size(); l ++) {
                if (ABmap.find(-1 * (C[k] + D[l])) != ABmap.end()) {
                    res += ABmap[-1 * (C[k] + D[l])];
                }
            }
        }
        return res;
    }
};
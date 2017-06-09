class Solution {
public:
    int hIndex(vector<int>& citations) {
    	if (citations.empty()) return 0;
        sort(citations.begin(), citations.end());
        int n = citations.size()-1, h = citations.size();
        int i = 0;
        while (citations[n-h+1] < h && n-h+2 < citations.size()) {
        	if (citations[n-h+2] >= h) return --h;
        	h--;
        }
        if (citations[n-h+1] >= h) return h;
        return 0;
    }
};
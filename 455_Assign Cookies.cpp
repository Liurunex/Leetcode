class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
        if (!s.size() || !g.size()) return 0;

		sort(s.begin(), s.end());
		sort(g.begin(), g.end());
		
		int count = 0, j = g.size()-1, i = s.size()-1;
		while (1) {
			if (count == g.size()) return count;
			if (s[i] >= g[j]) {
				count ++;	
				i --;
			}
			j --;
			if (i < 0 || j < 0) return count;
		}
	}
};
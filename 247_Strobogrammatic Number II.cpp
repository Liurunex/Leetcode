class Solution {
public:
	vector<string> findStrobogrammatic(int n) {
		vector<pair<int, int>> dict {{0,0}, {1,1}, {6,9}, {8,8}, {9,6}};
		vector<string> vres;
		string res (n, '0');
		dfshelper(dict, res, 0, n, vres);
		return vres;
	}

	void dfshelper(vector<pair<int, int>>& dict, string& res, int start, int& n, vector<string>& vres) {
		if (start >= n/2) {
			if (n&1) {
				res[n/2] = '0';
                vres.push_back(res);
                res[n/2] = '1';
                vres.push_back(res);
                res[n/2] = '8';
                vres.push_back(res);
			}
			else vres.push_back(res);
			return;
		}
		for (int i = 0; i < dict.size(); ++ i) {
            if (start == 0 && i == 0)
                continue;
			res[start] = dict[i].first+'0';
			res[n-1-start] = dict[i].second+'0';
			dfshelper(dict, res, start+1, n, vres);
			res[start] = 0;
			res[n-1-start] = 0;
		}
	}
};

/* the idea: DFS. 建立strobogrammatic数字的映射表，用dfs从0到n/2以此填表中数，同时填对应的n-1-i那个数字，NOTICE odd情况要在dfs
 * 到 n/2 时候进行补填中间那个数，只能是0,1,8
 * */
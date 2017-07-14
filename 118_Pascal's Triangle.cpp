class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		vector<int> firstline  (1, 1);
		vector<int> secondline (2, 1);
 		if (!numRows) return res;
 		res.push_back(firstline);
 		if (numRows == 1) return res;
 		res.push_back(secondline);
 		if (numRows == 2) return res;

		for (int i = 3; i <= numRows; ++ i) {
			vector<int> newline;
			newline.push_back(1);
			int a = 0, b =1;
			for (int j = 0; j < i-2; ++ j) {
				newline.push_back(res.back().at(a)+res.back().at(b));
				a ++;
				b ++;
			}
			newline.push_back(1);
			res.push_back(newline);
		}
		return res;
	}
};
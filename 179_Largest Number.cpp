class Solution {
private:
	static bool mycompa (string i, string j) {
        if (i == j) return 0;
		string ij = i + j;
		string ji = j + i;
		for (int k = 0; k < ij.length(); ++ k) {
			if (ij[k] - '0' < ji[k] - '0')
				return 0;
			if (ij[k] - '0' > ji[k] - '0')
				return 1;
		}
        return 0;
	}
public:
	string largestNumber(vector<int>& nums) {
		vector<string> test;
		for (int i = 0; i < nums.size(); ++ i) 
			test.push_back(to_string(nums[i]));
		sort(test.begin(), test.end(), mycompa);
		string res;
		for (int i = 0; i < test.size(); ++ i)
			res += test[i];
		return res[0] == '0' ? "0":res;
	}
};
/*
 * the idea is compare the string a+b and b+a to determine whether a or b should be place ahead
 */

class Solution {
public:
	int nextGreaterElement(int n) {
		string s = to_string(n);
		if (s.size() < 2) return -1;

		int i = s.size()-1;
        long res = -1;
		for (i; i >= 1; --i)
			if (s[i] > s[i-1])
				break;
		i --;

		if (i < 0)
			return -1;

		int reverGI = s.size()-1;
		while (s[reverGI] <= s[i])
			reverGI --;

		swap(s[i], s[reverGI]);
		sort(s.begin() + i + 1, s.end());

		istringstream iss(s);
		iss >> res;
		return res > INT_MAX ? -1:(int) res;
	}
};

/* the idea: math find next permutation, check 31 */
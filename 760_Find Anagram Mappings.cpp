class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		if (A.size() != B.size() || !A.size()) return {};
		unordered_map<int, int> mapping;

		for (int i = 0; i < B.size(); ++ i)
			mapping[B[i]] = i;

		vector<int> res (A.size(), -1);
		for (int i = 0; i < A.size(); ++ i)
			res[i] = mapping[A[i]];
		return res;
	}
};

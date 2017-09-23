class Solution {
public:
	bool isStrobogrammatic(string num) {
		if (!num.size()) return true;
		unordered_map<int, int> dict ({{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}});
		int left = 0, right = num.size()-1;
		while (left <= right) {
			if (dict.find(num[left]-'0') != dict.end() &&
				dict.find(num[right]-'0') != dict.end() &&
				dict[num[left]-'0'] == num[right]-'0') {
                if (left == right) return true;
				left ++;
				right --;
				continue;
			}
			return false;
		}
		return true;
	}
};
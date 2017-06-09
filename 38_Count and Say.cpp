class Solution {
public:
	string countAndSay(int n) {
		string number = "1";
		string next = "";
		char top;
		pair<char, int> dic ('1', 0);
		for (int i = 1 ; i < n; ++ i) {
			top = number[0];
			dic.first = top;
			dic.second = 0;
			for (int j = 0; j < number.size(); ++ j) {
				if (top != number[j] || j + 1 == number.size()) {
					cout << dic.first << " #: " << dic.second << endl;
					next += to_string(dic.second) + to_string(dic.first);
					dic.first = number[j];
					dic.second = 1;
				}
				else {dic.second ++; cout << "in" << endl;}
			}
			number = next;
			next = "";
		}
		return number;
	}
};

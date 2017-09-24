class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> pre;
		int sum = 0;
		for (string item:ops) {
			if (item == "D") {
				int score = 2*pre.back();
				pre.push_back(score);
				sum += score;
			}
			else if (item == "C") {
				sum -= pre.back();
				pre.pop_back();
			}
			else if (item == "+") {
				int sc1 = pre.back();
				pre.pop_back();
				int sc2 = pre.back();
				int score = sc1 + sc2;
				pre.push_back(sc1);
				pre.push_back(score);
				sum += score;
			}
			else {
				sum += stoi(item);
				pre.push_back(stoi(item));
			}
		}
		return sum;
	}
};
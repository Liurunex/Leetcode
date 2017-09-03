/* brute force, need reconsider*/
class Solution {
public:
	int maximumSwap(int num) {
		string new_str = to_string(num);
		string num_str;
		int candiate = num;
		int left = 0, right = new_str.length()-1;
		for (int left = 0; left < new_str.length()-1; left ++) {
			for (int right = new_str.length()-1; right > left; right --) {

				if (new_str[left] < new_str[right]) {
					num_str = new_str;
					char tem       = num_str[left];
					num_str[left]  = num_str[right];
					num_str[right] = tem;
					candiate = max(candiate, stoi(num_str));
					num_str.clear();
				}
			}
		}
		return candiate;
	}
};

/* O(n) solution: */
class Solution {
public:
	int maximumSwap(int num) {
		if (num < 10) return num; 
		string new_str = to_string(num);
		
		vector<pair<int, int>> minleft;
		minleft.push_back(make_pair(new_str[0], 0));
		for (int i = 1; i < new_str.length(); ++ i) {
			if (new_str[i] < minleft.back().first)
				minleft.push_back(make_pair(new_str[i], i));
			else minleft.push_back(minleft.back());
		}

		vector<pair<int, int>> maxright;
		maxright.push_back(make_pair(new_str.back(), new_str.length()-1));
		for (int i = new_str.length()-2; i >= 0; -- i) {
			if (new_str[i] > maxright.back().first)
				maxright.push_back(make_pair(new_str[i], i));
			else maxright.push_back(maxright.back());
		}

		for (int i = 0; i < new_str.size(); ++ i) {
			if (maxright.back().first != minleft[i].first) {
				new_str[maxright.back().second] = minleft[i].first;
				new_str[minleft[i].second]  = maxright.back().first;
				break;
			}
            maxright.pop_back();
		}

		return stoi(new_str);
	}
};

/*
the idea is: use a vector minfromleft to record the minimum number and its index 
for current pointer location viewing from its left, and a maxfromright to record the maximun number and its
index for current pointer location viewing from its right;
then we go through the two vector from left to right, once we find the value is different,
we have found the swap pair;
the proof is for i and j position (i < j), i will see more possibilities of max candiate from its right
while j will see more possibilities of min candiate from its left, however, i is higher digit than j
that means replacing i will grant us a more siginificant number, so do it
 */
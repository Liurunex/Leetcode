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
class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		string str = to_string(N);
		int pivot = -1;
		for (int i = 0; i < str.size()-1; i ++) {
			if (str[i] > str[i+1]) {
				pivot = lower_bound_helper(str, 0, i, str[i]);
				str[pivot] = str[pivot]-1;
				break;
			}
		}
		if (pivot == -1) return N;
		for (int i = pivot+1; i < str.size(); ++ i)
			str[i] = '9';
		return stoi(str);
	}
	int lower_bound_helper(string& str, int start, int end, char target) {
		while (start <= end) {
			int mid = start + (end - start)/2;
			if (str[mid] < target)
				start = mid+1;
			else end = mid-1;;
		}
		return start;
	}

};
/* the idea: Greedy + lower bound BS. 从高位到地位，找第一个non increasing index,
 * 用bs lower bound 方法找到这个index上连续数leftmost(针对这个数连续repeat)，将leftmost位置的
 * 数-1，然后将其后的数置9
 * */
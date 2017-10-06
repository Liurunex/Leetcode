class Solution {
public:
	string removeKdigits(string num, int k) {
		string res;
		int tokeep = num.size()-k;
		for (int i = 0; i < num.size(); ++ i) {
			while (res.size() > 0 && res.back() > num[i] && k > 0) {
				k --;
				res.pop_back();
			}
			res.push_back(num[i]);
		}
		/* to remove the last potential peak */
		res.erase(tokeep, string::npos);


		int zerohead = 0;
		while (zerohead < res.length()-1 && res[zerohead] == '0')
			zerohead ++;
		res.erase(0, zerohead);
		return !res.empty() ? res:"0";
	}
};
/* the idea: our though is to keep remove the first peak from our number, a greedy thought;
 * the slow solution keep erase from the string will cost much time and is inefficent, intead we
 * can use a stack thought to solve this problem: that is, we keep push num[i] into stack until we
 * find the num[i] > stack.top(), in this case we keep pop from stack until num[i] <= stack.top(), NOTICE
 * the thought here is to mantain a non-decreasing number order in stack, which is the smallest number;
 * the trick: we mush resize the stack after travaling num[], simple reason: the peak might have already
 * be removed from the stack, but the k is still postive, then we should remove number from the right to left,
 * so that we just erase all element in the back from  num.size()-k to end of stack; also notice to erase the 
 * zero head!
 */

/* slow solution without using thought of stack */
class Solution {
public:
	string removeKdigits(string num, int k) {
		while (k > 0 && !num.empty()) {
			k --;
			int dele_index = num.size()-1;
			for (int i = 0; i < num.size()-1; ++ i) {
				if (num[i] > num[i+1]){
					dele_index = i;
					break;
				}
			}
			num.erase(num.begin() + dele_index);
		}

		/* remove all head zeros */
		int zerohead = -1;
		for (int i = 0; i < num.length(); ++ i) {
			if (num[i] == '0') {
				zerohead ++;
				continue;
			}
			break;
		}
		if (zerohead == num.length()-1) num.clear();
		else num.erase(num.begin(), num.begin()+(zerohead+1));
		return !num.empty() ? num:"0";
	}
};

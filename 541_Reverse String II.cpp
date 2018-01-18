class Solution {
public:
	string reverseStr(string s, int k) {
		int start = 0;
		while (start < s.size()) {
            //cout << start << endl;
      
            int reveSize = start+k <= s.size() ? start+k:s.size();
            int index_sum = start + reveSize-1;
            int half = start+(reveSize-1-start)/2;
            //cout << index_sum << ": " << half << endl;
			for (int i = start; i <= half; ++ i) {
				if (i >= s.size()) break;
				
                char tem = s[i];
                s[i] = s[index_sum-i];
				s[index_sum-i] = tem;
                
			}
            //cout << s << endl;
			start += 2*k;
		}
		return s;
	}
};

/* the idea: String. We travel the string in interval of 2k, then for each peice
 * of 2k substring, we reverse the first k of it. The trick: when the rest substring
 * is less than k, then we should change the size if substr to reverse. The reverse part
 * we use the in-place method, that is we just go the first half of the k-length string,
 * the swap the first half with the rest half, take an eye on how to implement it without
 * error */
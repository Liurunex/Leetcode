class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> smap (26, 0);
		for (int i = 0; i < s1.length(); ++ i)
			smap[s1[i] - 'a'] ++;

		int left = 0, right = 0;
		for (; right < s2.length(); ++ right) {
			if ((-- smap[s2[right] - 'a']) < 0) {
				while (++ smap[s2[left ++] - 'a']) {}
			}
			else if (!smap[s2[right] - 'a'] && right-left+1 == s1.length())
				return 1;
		}

		return 0;
	}
};
/* inital two pointer wiht a hashtabel idea: we inital a hashtable to record
 * the characters inside s1, the we start our two-pointer version of "slide window";
 * the process is: start at s2: we decrease the current right edge key's value in hashtable, check the vlaue:
 * if it was qual to zero and the window size is equal to s1 length, we are done; 
 * if the value was not negative, that means the current s2 character is in s1, 
 * otherwise we should move the "slide window": keep move the left edge to right, increase that new left edge
 * key's vlaue in hashtable, if we find the new left edge key's value is equal to 0 the loop is end, go back 
 * to move right edge key in s2: the reason is we know the key's value in range [left, right) should all >= 0 and
 * the right key value is negative at most -1, to increase the new left edge key's value will refund the character
 * situation in s1, notice the terminating condition is not left == right, since we can refund the chracter to 0
 * before left reach right: give the e.g.: s1(adc), s2(dcda), if we make the terminate condition:left == right
 * we will miss the solution, since our new left edge will start at s2[2] not s2[1]!
 */

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> s1map (26, 0), s2map (26, 0);
		for (int i = 0; i < s1.length(); ++ i) {
			s1map[s1[i] - 'a'] ++;
			s2map[s2[i] - 'a'] ++;
		}
		if (s1map == s2map) return 1;
		for (int i = s1.length(); i < s2.length(); ++ i) {
			s2map[s2[i] - 'a'] ++;
			s2map[s2[i-s1.length()] - 'a'] --;
			if (s1map == s2map) return 1;
		}
		return 0;
	}
};
/* the simple idea: two hashtable to record the characters inside s1 and s2 respectively,
 * we set the slide window with length s1, which is actually the s2 hashtable; 
 * initially two hashtable allign each other, check if two hashtable are equal: if yes we
 * are done, otherwise we keep "slide" the window: decrease the value the left edge key,
 * increase the value of next edge key, then do the check process agains until we 
 * find two hashtables are equal or we go through the whole s2
 */

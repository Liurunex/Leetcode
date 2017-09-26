class Solution {
public:
	string convertToTitle(int n) {
		string res;
		if (!n) return "";
		while (n/26) {
			char zigit = !(n%26) ? 'Z':(n%26 - 1) + 'A';
			res  = zigit + res;
			if (!(n%26) && (n/26) == 1) return res;
			n = !(n%26) ? n/26-1:n/26;
		}
		char sigdigit = n%26 - 1 + 'A';
		res = sigdigit + res;
		return res;
	}
};
/* the idea: using what base conversion by diveide and mode
 * the trick part is the corner case, NOTICE we should add
 * 'Z' when we got remaider 0 and minus the N by 1 as it has
 * carry，furthemore the 26 case is especially speical
 */

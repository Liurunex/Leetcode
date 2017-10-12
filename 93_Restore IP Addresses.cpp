class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string ipaddress;
		helper (s, 0, ipaddress, 3, res);
		return res;
	}

	void helper(string& s, int start, string ipaddress, int level,
		vector<string>& res) {
		if (s.length()-1-start < level) return;
		if (level == 0){
			int length = s.length()-1-start;
			if (length > 2 || (s[start] == '0' && length > 0))
				return;
			string last = s.substr(start);
			if (stoi(last) > 255)
				return;
			ipaddress += last;
			res.push_back(ipaddress);
		}

		if (s[start] == '0') {
			ipaddress += "0.";
			start ++;
			helper (s, start, ipaddress, level-1, res);
			return;
		}

		string cur;
		for (int i = start; i < s.length(); ++ i) {
			if (i-start > 2 || s.length()-1-i < level) return;
			cur += s[i];
			if (stoi(cur) <= 255)
				helper(s, i+1, ipaddress+cur+".", level-1, res);
			else return;
		}
	}
};
/* the ided: DFS, divide the string into four part, in each level of DFS, we just find a 
 * valid sequnce number for this part of ip address, then we use dfs to go next level by using
 * this sequence number until we reach the last level; the last level is simple, just judge if 
 * the rest part is valid and if so we find a solution
 */

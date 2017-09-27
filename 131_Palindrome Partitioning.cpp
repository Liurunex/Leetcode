class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> curres;
		backtrackhelper(res, curres, s);

		return res;

 	}

 	void backtrackhelper(vector<vector<string>>& res, vector<string> curres, string s) {
 		if (!s.length()) {
 			res.push_back(curres);
 			return;
 		}
 		
 		for (int i = 0; i < s.length(); ++ i) {
 			string leftsub = s.substr(0, i+1);
 			int leftptr = 0, rightptr = i, ispalindrome = 1;
 			while (leftptr < rightptr) {
 				if (leftsub[leftptr] != leftsub[rightptr]) {
 					ispalindrome = 0;
 					break;
 				}
 				leftptr ++;
 				rightptr --;
 			}
 			if (ispalindrome) {
 				curres.push_back(leftsub);
				backtrackhelper(res, curres, s.substr(i+1));
				curres.pop_back();
			}
 		}
 	}
};
/* the idea: a basic backtracking problem, just divide the string from begin to end, test
 * if the left side part is palindrome, if so we recursive call right side part as a 
 * new stirng into the backtracking function
 */

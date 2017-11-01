class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
		string allsen = "";
		for (string word:sentence)
			allsen += word + " ";
		/* ["hello", "world"] -> "hello_world_"*/
		int len = allsen.length(), res = 0, windex = 0;;
		for (int i = 0; i < rows; ++ i) {
			int colremains = cols;
			while (colremains > 0) {
				if (sentence[windex].length() <= colremains) {
					/* try to place a word */
					colremains -= sentence[windex].length();
					/* the case that word was not palced at end need whitespace*/
					if (colremains > 0) colremains --;
					windex ++;
					/* the case we have placed a whole sentence */
					if (windex >= sentence.size()) {
						/* to deal with case where cols >> sentence length, 
						 * thre res should plus the current sentence we just add
						 * and other sentecnes where colremains allow use to do,
						 * notice we should also update the colremians as well
						 */
						res += 1 + colremains/len;
						colremains %= len;
						windex = 0;
					}
				}

				else break;
			}
		}
		return res;
	}
};

/* TLE solution */
class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
		int crow = 0, ccol = -1, res = 0;
		while (1) {
			res ++;
			for (int i = 0; i < sentence.size(); ++ i) {
				ccol += sentence[i].size() + 1;
				if (ccol > cols) {
					i --;
					ccol = -1;
					if ((++ crow) == rows) return i == sentence.size()-1 ? res : res-1;
				}
				else if (ccol == cols) {
					ccol = -1;
					if ((++ crow) == rows) return i == sentence.size()-1 ? res : res-1;
				}
			}
		}
		return res;
	}
};

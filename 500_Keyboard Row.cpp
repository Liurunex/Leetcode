class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3{'z','x','c','v','b','n','m'};

        for (string word:words) {
        	int inrow1 = 0, inrow2 = 0, inrow3 = 0;
        	for (char cha:word) {
        		cha += cha < 'a' ? 32:0;
        		if (row1.count(cha)) inrow1 = 1;
        		else if (row2.count(cha)) inrow2 = 1;
        		else if (row3.count(cha)) inrow3 = 1; 
        		if (inrow1 + inrow2 + inrow3 > 1) break;
        	}
        	if (inrow1 + inrow2 + inrow3 == 1)
        		res.push_back(word);
        }
        return res;
	}
};
/* the idea: built three hashset to store 3 rows' letters respectively;
 * we use three bool vaules to check how many sets are involved in to 
 * form a word; once there is more than 1, break; once there is still
 * only one involved in afger completely checking one word, push it into
 * our result
 */

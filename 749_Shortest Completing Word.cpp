class Solution {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		vector<int> diction (26, 0);

        int maxlen = INT_MAX, index = -1;
		for (int j = 0; j < words.size(); ++ j) {
			for (int i = 0; i < words[j].size(); ++ i) {
				char curchar = tolower(words[j][i]);
				if (curchar < 'a' || curchar > 'z')
					continue;
				diction[curchar-'a'] ++;
			}
			int found = 1;
			for (int i = 0; i < licensePlate.size(); ++ i) {
				char curchar = tolower(licensePlate[i]);
				if (curchar < 'a' || curchar > 'z')
					continue;
				int charindex = curchar - 'a';
				if (diction[charindex] > 0)
					diction[charindex] --;
				else {
					found = 0;
					break;
				}
			}
			if (found) {
                //cout << "found" << endl;
				if (maxlen > words[j].size()) {
					maxlen = words[j].size();
					index  = j;
				}
			}
            diction.clear();
            diction.resize(26, 0);
		}
        //cout << index << endl;
       	return words[index];
	}
};
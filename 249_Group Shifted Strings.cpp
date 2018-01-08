class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) {
		map<int, vector<string>> countMap;
		for (string word:strings)
			countMap[word.size()].push_back(word);
		vector<vector<string>> res;
		if (countMap.count(1))
			res.push_back(countMap[1]);

		for (auto i = countMap.begin(); i != countMap.end(); ++ i) {
            if (i->first == 1) continue;
			unordered_map<string, vector<string>> dictionary;
			vector<int> visited (i->second.size(), 0);
			for (int j = 0; j < i->second.size(); ++ j) {
                if (visited[j]) continue;
				for (int k = j+1; k < i->second.size(); ++ k) {
                    if (dothecheck(i->second[j], i->second[k]) && !visited[k]) {
						dictionary[i->second[j]].push_back(i->second[k]);
						visited[j] = 1;
                        visited[k] = 1;
					}
				}
                if (dictionary.count(i->second[j])) {
                    dictionary[i->second[j]].push_back(i->second[j]);
                    res.push_back(dictionary[i->second[j]]);
                }
			}
            for (int t = 0; t < visited.size(); ++ t)
                if (!visited[t])
                    res.push_back({i->second[t]});
                    
		}
		return res;
	}

	bool dothecheck(string& a, string &b) {
		int distance = a[0] - b[0];
		for (int i = 1; i < a.length(); ++ i) {
			if (distance != (a[i]-b[i]) && (abs(distance) + abs(a[i]-b[i]) != 26))
				return false;
		}
		return true;
	}
};
/* the idea: hashmap; First group all strings based on the length, that is mapping the
 * size of string to the vector of all string with that size; Then for each group (strings
 * with same size), we find out how to group them. We need a hashmap to mapping the key to
 * all its shifting mutation strings. To do that, we first set each string as the possible key,
 * then we itearate all other string in same size to check if they belong to same group, this is
 * done by by check if char on same position share same distance of the sum of absolute vlalue equal
 * to 26. Notice that, we have to set a visited map to avoid duplicate grouping, meanwhile we don't
 * really iterate each other strings when selecting the key, we only iterate those strings behind the
 * key position, that is combination theory.
*/

/* the short answer is better: we make a copy of each string, shift them to start with 'a', then
 * use a hashmap to mapping the key to the rows we placed it in our final result
 */
class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) {
		map<string, int> mp;
		int cnt = 0;
		vector<vector<string>> res;
		for (string &str:strings) {
			string key = str;
			while (key[0] != 'a') {
				for (char &c:key)
					c = ((c+1) > 'z') ? 'a':c+1;
			}
			if (!mp.count(key)) {
				mp[key] = cnt ++;
				res.push_back(vector<string>());
			}
			res[mp[key]].push_back(str);
		}
		return res;
	}
}
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> pmap;
         priority_queue<pair<int, char>> ppq;
        string res = "";
        int i = 0;
        
        for (i = 0; i < (int)s.size(); i++) {
        	if (!pmap.count(s[i])) pmap[s[i]] = 1;
        	else pmap[s[i]] ++;
        }

        while (!pmap.empty()) {
        	ppq.push(make_pair(pmap.begin()->second, pmap.begin()->first));
        	pmap.erase(pmap.begin());
        }

        while (!ppq.empty()) {
        	pair<int, char> tem =ppq.top();
        	res.append(tem.first, tem.second);
        	ppq.pop();
        }
        return res;
    }
};
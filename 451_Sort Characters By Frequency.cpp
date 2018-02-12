class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> dict, appera;
        for (int i = 0; i < s.size(); ++ i) {
            if (!appera.count(s[i]))
                appera[s[i]] = i; 
            dict[s[i]] ++;
        }
        auto comp = [&appera](pair<int, char> x, pair<int, char> y) -> bool {
            return x.first < y.first || x.first == y.first && appera[x.second] > appera[y.second];
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)> pq(comp);
        
        for (auto i = dict.begin(); i != dict.end(); ++ i)
            pq.push({i->second, i->first});
        
        string res;
        while (pq.size()) {
            int count = pq.top().first;
            while (count) {
                res += pq.top().second;
                count --;
            }
            pq.pop();
        }
        return res;
    }
};
// pq solution added

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
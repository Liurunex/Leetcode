class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words2.size() != words1.size()) return false;
        unordered_map<string, unordered_set<string>> simipairs;
        for (auto item:pairs)
        	simipairs[item.first].insert(item.second);
        	
        for (int i = 0; i < words1.size(); ++ i) {
            
        	if (words1[i] == words2[i])
        		continue;
        	if ((simipairs.count(words1[i]) && simipairs[words1[i]].count(words2[i])) ||
        		(simipairs.count(words2[i]) && simipairs[words2[i]].count(words1[i])))
        		continue;
    		return false;
        }
        return true;
    }
};

/* the idea: burte force + hash tabel + hash set */
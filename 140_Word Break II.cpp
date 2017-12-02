class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    	vector<string> res;
    	unordered_set<string> dict(wordDict.begin(), wordDict.end());
    	vector<bool> hasSolution (s.length()+1, 1);
    	string curres;
        DFS(s, curres, dict, res, hasSolution, 0);

    	return res;
    }

    void DFS(string& s, string& curres, unordered_set<string>& dict, 
    	vector<string>& res, vector<bool>& hasSolution, int start) {
    	if (start == s.length()) {
    		res.push_back(curres.substr(0, curres.size()-1));
            /*
            curres.pop_back();
    		res.push_back(curres);
            */
    		return;
    	}

        if (!hasSolution[start])
            return;
    	string combine;
    	for (int i = start; i < s.length(); ++ i) {
    		combine += s[i];
    		
            if (dict.count(combine) && hasSolution[i+1]) {
                int ori_size = res.size();
                curres += combine + " ";
    			DFS(s, curres, dict, res, hasSolution, i+1);
                if (ori_size == res.size())
    			    hasSolution[i+1] = 0;

                for (int i = 0; i < combine.size()+1; ++ i)
    			    curres.pop_back();
            }
    		
            
    	}
    }
};

/* the idea: DFS Backtracking + Pruning. The basic idead is to use DFS
 * backtracking directly to check each possibility. However DFS can do
 * much duplicate case, so that we should add a helper hasSolution vector
 * where hasSolution[i] means if it is possible to break the string from i to end
 * based on the given dictionary: in more detail, we first check if hasSolution[i]
 * is true, if so we keep do the DFS backtracking, otherwise we skip this case,
 * this is prune algorithm take effects
 */
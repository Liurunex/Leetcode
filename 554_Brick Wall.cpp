class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
    	unordered_map<int, int> lenmap;
    	int maxbricklen = 0;
        for (int i = 0; i < wall.size(); ++ i) {
        	int lenofbricks = 0;
        	for (int j = 0; j < wall[i].size()-1; ++ j) {
        		lenofbricks += wall[i][j];
        		if (lenmap.find(lenofbricks) == lenmap.end())
        			lenmap[lenofbricks] = 1;
        		else lenmap[lenofbricks] ++;
        		maxbricklen = max(maxbricklen, lenmap[lenofbricks]);
        	}
        }
        return wall.size() - maxbricklen;
    }
};

/* the idea is to use the hashtable recording the frequency of length appering 
	before the current brick in a row (include); go thorught the whole wall, and 
	get the max frequency of length, which is the brick we gonna draw a line
*/
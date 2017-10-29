class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, 
    	vector<int>& p3, vector<int>& p4) {
        unordered_set<int> dict;
        dict.insert(dist(p1, p2));
        dict.insert(dist(p1, p3));
        dict.insert(dist(p1, p4));
        dict.insert(dist(p2, p3));
        dict.insert(dist(p2, p4));
        dict.insert(dist(p3, p4));
        return dict.size() == 2 && !dict.count(0);
    }

    int dist(vector<int> &x, vector<int> &y) {
    	return pow(x[0]-y[0], 2) + pow(x[1]-y[1], 2);
    }
};
/* the idea: to form a square is that all distances among nodes only
 * have two possible values, based on that
 */

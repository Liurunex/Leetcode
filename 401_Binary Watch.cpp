class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int hn;
        vector<string> res;
        vector<int> hour{8, 4, 2, 1};
        vector<int> minute{32, 16, 8, 4, 2, 1};
        for (hn = 0; hn <= 4; hn ++) {
        	if (num - hn < 0) break;
        	vector<int> hcandiate;
        	vector<int> mcandiate; 
        	helpgen(hn, 0, 0, hour, hcandiate);
        	helpgen(num-hn, 0, 0, minute, mcandiate);

        	for (int h2: hcandiate) {
        	    if (h2 > 11) continue;
        		for (int m2: mcandiate) {
        		    if (m2 > 59) continue;
        			string singRes = to_string(h2) + (m2 < 10 ? ":0" : ":") + to_string(m2);
        			res.push_back(singRes);
        		}
        	}
        }
        sort(res.begin(), res.end());
        return res;
    }

    void helpgen(int n, int index, int sum, vector<int> &times, vector<int> &result) {
    	if (n == 0) {
    		result.push_back(sum);
    		return;
    	}
    	for (int i = index; i < times.size(); i++) {
    		helpgen(n-1, i+1 , sum + times[i], times, result);
    	}
    }
};
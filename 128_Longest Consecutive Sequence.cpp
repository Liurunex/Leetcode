class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> hashtable;
        int i;
        for (i = 0; i < nums.size(); i++)
        	hashtable.insert(nums[i]);
        
        int cval, clen = 1, maxlen = 0;
       	while (!hashtable.empty())  {
       	    clen = 1;
        	cval = *(hashtable.begin());
        	hashtable.erase(cval);
			clen = hashhelper(hashtable, cval+1, clen, 1);
			clen = hashhelper(hashtable, cval-1, clen, 0); 
			maxlen = max(clen, maxlen);  
        }
        return maxlen;
    }

    int hashhelper(unordered_set<int>& hashtable, int val, int clen, int op) {
    	if (hashtable.count(val)) {
    		hashtable.erase(val);
    		clen ++;
    		if (op) clen = hashhelper(hashtable, val+1, clen, op);
    		else clen = hashhelper(hashtable, val-1, clen, op);
		}
		return clen;
    }
};
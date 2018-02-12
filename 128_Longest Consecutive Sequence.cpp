class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict;
        for (int i:nums)
            dict.insert(i);
        int res = 0;
        for (int i:nums) {
            if (!dict.count(i)) continue;
            dict.erase(i);
            int pre = i-1, next = i+1;
            while (dict.count(pre)) 
                dict.erase(pre --);
            while (dict.count(next))
                dict.erase(next ++);
            res = max(res, next-pre-1);
        }
        return res;
    }
};
// hashset ways, directly look for next and pre

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
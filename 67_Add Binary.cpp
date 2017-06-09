class Solution {
public:
    string addBinary(string a, string b) {
    	string res = "";
    	int i = a.length()-1, j = b.length()-1;
    	int adigit, bdigit, deposit = 0;
    	
    	while (i >= 0 || j >= 0 || deposit == 1) {
    	    adigit = bdigit = 0;
    		if (i >= 0 ) adigit = int(a[i--]) - '0';
    		if (j >= 0) bdigit = int(b[j--]) - '0';
    		
    		int cureent = adigit + bdigit + deposit;
    		
    		if (cureent == 1) deposit = 0;
    		else if (cureent == 2) {
    			cureent = 0;
    			deposit = 1;
    		}
    		else if (cureent == 3) {
    			cureent = 1;
    			deposit = 1;
    		}

    		res = to_string(cureent) + res;
    	}
    	return res;
    }
};
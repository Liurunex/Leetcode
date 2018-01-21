class Solution {
public:
	int compareVersion(string version1, string version2) {
		int vnum1 = 0, vnum2 = 0;
		for (int i = 0, j = 0; (i < version1.size() || j < version2.size());) {
			while (i < version1.size() && version1[i] != '.')
				vnum1 = vnum1*10 + (version1[i ++] - '0');

			while (j < version2.size() && version2[j] != '.')
				vnum2 = vnum2*10 + (version2[j ++] - '0');
			if (vnum1 == vnum2) {
				vnum1 = vnum2 = 0;
				i ++;
				j ++;
				continue;
			}
			return vnum1 > vnum2 ? 1:-1;
		}
		return 0;
	}
};
/* the idea: String Split + String Compare. 
 * First Method: itearate both string, compute
 * the int value until reached '.' or end, if the two value is not equal, we are done;
 * otherwise we have to reset the two value to 0 and keep iterating to next '.' or end
 * for comparing;
 * Second Method: same thought as above, the only difference is we concerned that the version
 * number might have excess the INT_MAX so that we do not compute the value but directly comparing
 * each of the substr end at '.' one by on on char unit. This one requires removing all 0 at begin of
 * each substring. */

class Solution {
public:
	string splitString(string& str, int& start) {
		while (str[start] == '0')
			start ++;
		string substr;
		while (start < str.size()) {
			if (str[start] == '.')
				break;
			substr += str[start ++];
		}
        start ++;
		return substr;
	}

	int compare(string& x, string& y) {
		if (x.size() == y.size()) {
			if (!x.size()) return 0;
			for (int i = 0; i < x.size(); ++ i) {
				if (x[i] == y[i])
					continue;
				return x[i] > y[i] ? 1:-1;
			}
            return 0;
		}
		else return x.size() > y.size() ? 1:-1;
	}
    
    int finalCheck(string &version2, int& j) {
        while (j < version2.size()) {
            if (version2[j] != '.' && version2[j] != '0')
                return 1;
            j ++;
        }
        return 0;
    } 

	int compareVersion(string version1, string version2) {
		int i = 0, j = 0;
		while (i < version1.size() && j < version2.size()) {
			string c1 = splitString(version1, i);
			string c2 = splitString(version2, j);
			int cres = compare(c1, c2);
			if (!cres)
				continue;
			return cres;
		}
		if (i >= version1.size()) 
			return !finalCheck(version2, j) ? 0:-1;
		else 
			return !finalCheck(version1, i) ? 0:1;
	}
};
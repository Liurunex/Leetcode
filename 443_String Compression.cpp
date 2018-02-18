class Solution {
  public:
    int compress(vector<char> &chars) {
        int start = 0, counter = 0;
        for (int i = 0; i < chars.size(); i++) {
            counter++;
            if (i == chars.size() - 1 || chars[i] != chars[i + 1]) {
                chars[start ++] = chars[i];
                if (counter > 1) {
                    string temp = to_string(counter);
                    for (char c:temp) {
                        chars[start ++] = c;
                    }
                }
                counter = 0;
            }
        }
        return start;
    }
};

class Solution {
public:
	int compress(vector<char>& chars) {
		if (chars.size() < 2) return chars.size();
		int size = chars.size(), index = 1, counter = 1;
		char curchar = chars[0];
		
		while (index < size) {
			if (curchar == chars[index])
				counter ++;
			else {
				chars.push_back(curchar);
				if (counter > 1) {
					string tem = to_string(counter);
					for (char it:tem)
						chars.push_back(it);
				}
				counter = 1;
				curchar = chars[index];
			}
			index ++;
		}
		chars.push_back(curchar);
		if (counter > 1) {
			string tem = to_string(counter);
			for (char it:tem)
				chars.push_back(it);
		}
		chars.erase(chars.begin(), chars.begin()+size);
		return chars.size();
	}
};

/* the idea: this append method is not a in-place one, what you should do is keep swap
 * between position!!!!
 */

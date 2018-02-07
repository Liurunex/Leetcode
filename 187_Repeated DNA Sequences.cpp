class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<int, int> dict;
		vector<string> res;
		for (int i = 0; i+9 < s.size(); ++ i) {
			string tem = s.substr(i, 10);
			int code = encode(tem);
			if (dict.count(code)) {
				if (dict[code] == 1)
					res.push_back(tem);
				dict[code] ++;
			}
			else dict[code] = 1;
		}
		return res;
	}
	int encode(string& str) {
		int code = 0;
		for (char c:str) {
			code <<= 2;
			switch(c) {
				case 'A': code += 0; break;
				case 'C': code += 1; break;
				case 'T': code += 2; break;
				case 'G': code += 3; break;
			}
		}
		return code;
	}
};
/* the idea: HashMap; 直接的做法是把10位string存进hashmap, 考虑内存占用太大，可以把每个
 * 字符转换成2-bit来表示，然后10位string变成20-bit的二进制，可以直接转换成int存
 */
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> dict;
		vector<string> res;
		for (int i =0; i + 9 < s.size(); ++ i) {
			string tem = s.substr(i, 10);
			if (dict.count(tem)) {
                if (dict[tem] == 1)
                    res.push_back(tem);
                dict[tem] ++;
            }
			else dict[tem] = 1;
		}
		return res;
	}
};

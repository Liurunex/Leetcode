/* run  6ms, seems slowly*/
class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0, maxl = 0, start = 0, level = 0;
        bool newline = false;
        string str;
        map<int, int> level_length; 
        level_length[0] = 0;
    
        for (i = 0; i < (int)input.size(); i++) {
            if (input[i] == '\t') {
                level ++;
                continue;
            }
        
            if (input[i] == '\n' || i == (int)input.size() - 1) {
                level_length[level] ++;
                str = input.substr(start, i - start);
                if (str.find('.', 0) != string::npos) {
                    if (i != (int)input.size() - 1)
                        level_length[level] --;
                    maxl = max(maxl, level_length[level]);
                }
                str.clear();
                start = i + 1;
                level = 0;
                newline = true;
                continue;
            }
        
            if (!level_length.count(level) || newline) {
                level_length[level] = level_length[level - 1] + 1;
                newline = false;
            }
            else  level_length[level] ++;
        }
        return maxl;
    }
};
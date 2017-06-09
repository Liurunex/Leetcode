class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0, maxl = 0, start = 0, level = 0;
        bool newline = true;
        string str;
        map<int, int> level_lenght;
        level_lenght[0] = 0;
        for (i = 0; i < input.size(); i++) {
          
          if (input[i] == '\t') {
            level ++;
            continue;
          }

          if (input[i] == '\n') {
            str = input.substr(start, i - start);
            if (str.find('.', 0) != string::npos && level > 1)
              maxl = max(maxl, level_lenght[level]);
            str.clear();
            start = i + 1;
            level = 0;
            newline = true;
            continue;
          }
        
          if (!level_lenght.count(level) || newline) {
            level_lenght[level] = level_lenght[level - 1] + 1;
            newline = false;
          }
          else  level_lenght[level] ++;
        }

      return maxl;
    }
};
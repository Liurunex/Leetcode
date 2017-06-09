class Solution {
public:
    void reverseWords(string &s) {
        vector<char*> dic;
        char *p = new char[s.size()+1];
        strcpy(p, s.c_str());
        
        char *word = strtok(p, " ");
        while(word != NULL) {
            dic.push_back(word);
            word = strtok(NULL, " ");
        }
        
        int len = dic.size();
        int i = 0;
        s.clear();
        for (i = len-1; i >= 0; i--) {
            s += dic[i];
            if (i != 0)
                s += " ";
        }
    }
};
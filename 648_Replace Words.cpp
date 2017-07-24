class Solution {
public:
        string replaceWords(vector<string>& dict, string sentence) {
        string res;
        if (dict.empty() || !sentence.length()) return res;
                queue<string> myqueue;
                istringstream iss(sentence);
                string tok;
                while (getline(iss, tok, ' '))
                myqueue.push(tok);

        while (!myqueue.empty()) {
                string word = myqueue.front();
                myqueue.pop();
                for (int i = 0; i < dict.size(); ++ i) {
                        if (word.find(dict[i]) == 0)
                                word = word.length() > dict[i].length() ? dict[i]:word;
                }
                res += word + " ";
        }
        res.pop_back();
        return res;
        }
};
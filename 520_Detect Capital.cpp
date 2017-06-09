class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word == "") return true;
        bool res1 = true, res2 =true;
        /* case 2,3*/
        for (int i = 1; i < word.length(); i++) {
            if (int(word[i]) > 64 && int(word[i]) < 91) {
                res1 = false;
                break;
            }
        }
        /* all captial */
        for (int i = 0; i < word.length(); i++) {
            if (int(word[i]) < 65 || int(word[i]) > 90){
                res2 = false;
                break;
            }
        }
        cout << "case1: " << res1 << "case2: " << res2 << endl;
        return (res1 || res2);
    }
};
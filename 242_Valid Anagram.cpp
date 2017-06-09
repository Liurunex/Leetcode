class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> dic;
        for (int i = 0; i < s.length(); i++) {
            if (dic.find(s[i]) == dic.end())
                dic[s[i]] = 1;
            else dic[s[i]] ++;
        }
        for (int i = 0; i < t.length(); i++) {
            if (dic.find(t[i]) == dic.end())
                return false;
            else dic[t[i]] --;
        }

        for (auto& word: dic) 
            if (word.second != 0) 
                return false;
        return true;
    }
};
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> dict;
        for (char i:J)
            dict.insert(i);
        int res = 0;
        for (char i:S)
            if (dict.count(i))
                res ++;
        return res;
    }
};
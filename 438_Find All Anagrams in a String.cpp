/* slow solution 66ms using two hashtable*/
class Solution {
public:
     vector<int> findAnagrams(string s, string p) {
          if (s.size() == 0 || p.size() > s.size()) return {};
          vector<int> res;
          unordered_map<char, int> pdic, ssdic;
          for (int i = 0; i < p.size(); ++i) {
               pdic[p[i]] += 1;
               ssdic[s[i]] += 1;
          }
          if (pdic == ssdic) res.push_back(0);

          for (int i = p.size(); i < s.size(); ++i) {
               ssdic[s[i]] += 1;
               ssdic[s[i - p.size()]] -= 1;
               if (ssdic[s[i - p.size()]] == 0)
                    ssdic.erase(s[i - p.size()]);
               if (ssdic == pdic)
                    res.push_back(i - p.size() + 1);
          }
          return res;
     }
};

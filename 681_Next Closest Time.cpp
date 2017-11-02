class Solution {
public:
	string nextClosestTime(string time) {
		set<int> dict_set ({time[0]-'0', time[1]-'0', time[3]-'0', time[4]-'0'});
		vector<int> sort_dict (dict_set.begin(), dict_set.end());
		sort(sort_dict.begin(), sort_dict.end());
				
		string res = time;
		for (int i = time.length()-1; i >= 0; -- i) {
			if (time[i] == ':')
				continue;

			int pos = lower_bound(sort_dict.begin(), sort_dict.end(), time[i]-'0') - sort_dict.begin();
			res[i] = time[i]-'0' == sort_dict.back() ? sort_dict[0]+'0':sort_dict[pos+1]+'0';
			
            if (time[i]-'0' < sort_dict.back()) {
				switch (i) {
					case 4:
						return res;
					case 3:
						if (res[i] < '6') return res;
                        break;
					case 1:
						if (res[0] != '2' || res[i] < '4') {
                            return res;
                        }
                        break;
					case 0:
						if (res[i] < '3') return res;
				}
                res[i] = sort_dict[0]+'0';
			}
		}
		return res;
	}
};

/* the idea: the brute froce idea can work (just itertate totally 1440 possible minute points in clockwise to find the first
 * one whose all number inside number dictionary). The solution here is to determine each time digit from lowe to high.
 * We check if currrent time digit has excessed the largest we have, once that happened, that means we have to go next whole
 * higher time circle (in 1 hour/10 minute or 10 hour/1 day), so that set the current time digit to minium we can access, this
 * is to ensure that after "improve" higher time digit, we catch the minimum one allowed! In other case, we just set the current 
 * time digit to next higher one in sorted dictionary. Then we should determine our position: in minute or hour.
 * the trick: NOTICE that we must set the current time digit to minimium one if we cannot return in switch statement, namely after
 * we try to "change" the lower time digit and find the new form time is not valid, we should set the current time digit to minimum
 * candidate so that it will not violate our "closet" rule in next higher time digit iteration
 */
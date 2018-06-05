class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		int n = hand.size();
		if (n%W) {
			// cout << "exit 1" << endl;
            return false;
        }
		
		map<int, int> all;
		for (int num:hand)
			all[num] ++;
        /*
        for (auto i = all.begin(); i != all.end(); ++ i)
            cout << i->first << " -> " << i->second << endl;
	    */
        
		auto start = all.begin();
		while (start != all.end()) {
			auto it = start;
			int fin = it->first, fir = it->second, count = 1, flag = 0;
            
			while (count < W) {
				it ++;
				if (it == all.end() || fin+count != it->first || it->second < fir) {
                    //cout << count << ": " << fin << " -> " << it->first << " and " << it->second << endl;
					//cout << "exit 2" << endl;
                    return false;
                }
				it->second -= fir; 
				if (it->second && !flag) {    
					flag  = 1;
					start = it; 
				}
                count ++;
			}
			if (!flag)
				start = ++ it;
		}
		return true;
	}
};
/* the idea: map with sorted feature, iterate the map to build all consecutive gorups, NOTICE map.erase
   is not needed so that we can aovid erase prcoess to accelerate the running speed */
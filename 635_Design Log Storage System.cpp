/* convert the string to 1 12-digit number, store it in map*/
class LogSystem {
public:
	map<long, int> storeMap;
	LogSystem() {
	}

	void put(int id, string timestamp) {
		string timeSeg;
		string timeStr;
		int isyear = 1;
		istringstream iss(timestamp);
		while(getline(iss, timeSeg, ':')) {
			if (isyear) {
				timeSeg = timeSeg.substr(2,2);
				isyear = 0;
			}
			timeStr += timeSeg;
		}
		long timeInt = stol(timeStr);
		
		if (storeMap.find(timeInt) != storeMap.end())
			cout << "collision" << endl;
		else {
			storeMap[timeInt] = id;
			cout << "insert: " << timeInt << " -> " << storeMap[timeInt] << endl;
		}
	}
	
	vector<int> retrieve(string s, string e, string gra) {
		map<long, int>::iterator i;
		string ssSeg, eeSeg;
		string sstimeStr, eetimeStr;
		int isyear = 1;
		istringstream is(s);
		istringstream ie(e);
        while(getline(is, ssSeg, ':') && getline(ie, eeSeg, ':')) {
			if (isyear) {
				ssSeg = ssSeg.substr(2,2);
				eeSeg = eeSeg.substr(2,2);
				isyear = 0;
			}
			sstimeStr += ssSeg;
			eetimeStr += eeSeg;
		}
        long ss = stol(sstimeStr);
        long ee = stol(eetimeStr);
        string scurtail = "0", ecurtail = "0", esupply = "0";
        string supply = "999999999999";
        int curtail_pos = 0;
        
        if(gra == "Year") 			curtail_pos = 2;
        else if (gra == "Month") 	curtail_pos = 4;
		else if (gra == "Day")		curtail_pos = 6; 
		else if (gra == "Hour") 	curtail_pos = 8; 
		else if (gra == "Minute")	curtail_pos = 10; 
     
        if (curtail_pos) {
        	scurtail = sstimeStr.substr(curtail_pos); 
			ecurtail = eetimeStr.substr(curtail_pos);
            esupply  = supply.substr(curtail_pos);
		}
		long sss = ss - stol(scurtail);
		long eee = ee - stol(ecurtail) + stol(esupply);
		cout << sss << " to " <<  eee << endl;

		vector<int> res;
		map<long, int>::iterator itlow, itup;
		itlow = storeMap.lower_bound(sss);
		itup  = storeMap.upper_bound(eee);
		//itup --;
		cout << "lower: " << itlow->second << endl;
		//cout << "upper: " << itup->second << endl;
		
		for (i = itlow; i != itup; ++ i) 
			res.push_back(i->second);
		return res;
	}
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */


class MyCalendar {
private:
	vector<pair<int,int>> storage;
public:
	MyCalendar() {
	}

	bool book(int start, int end) {
		if (!storage.size()) {
			storage.push_back({start, end});
			return true;
		}

		int left = 0, right = storage.size()-1;
		while (left <= right) {
			int mid = left + (right - left)/2;
			if (storage[mid].second < start)
				left = mid+1;
			else right = mid-1;
		}
		//cout << start << " - " << end << " at: "<< left << endl;
		if (storage[left].second == start)
			left ++;
		if (left < storage.size() && end > storage[left].first) 
			return false;

		storage.insert(storage.begin()+left, {start, end});
		return true;
	}
};

/* the idea: almost same as meeting room. As it is not allowed
 * to have overlap intervals, then we just use binary search to find the
 * position where our incoming intervals should be place, and then test
 * if it was overlapped with the interval next to it*/

class MyCalendarTwo {
private:
	map<int, int> storage;
public:
	MyCalendarTwo() {
	}

	bool book(int start, int end) {
		storage[start] ++;
		storage[end] --;
		int sum = 0;
		for (auto i = storage.begin(); i != storage.end(); ++ i) {
			sum += i->second;
			if (sum == 3) {
				storage[start] --;
				storage[end] ++;
				return false;
			}
		}
		return true;
	}
};
/* the: same as meeting room II, we use a tree-map to keep tracking of all start time
 * and end time, that is, once we increase the value of "start" key while decreasing 
 * the value of "end" key. So that we can go through the whole the map and add the 
 * values, so that we know once there is 3 appearing as sum, it is invalid of this 
 * coming book, otherwise we will keep the incoming book in
 * */
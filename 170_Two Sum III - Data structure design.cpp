class TwoSum {
private:
	unordered_map<int, int> theset;
public:
	/** Initialize your data structure here. */
	TwoSum() {

	}

	/** Add the number to an internal data structure.. */
	void add(int number) {
		theset[number] ++;
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) {
		for (auto i = theset.begin(); i != theset.end(); ++ i) {
			int target = value - i->first;
			if (theset.find(target) != theset.end()) {
				if (target != i->first || i->second > 1) return true;
			}
		}
		return false;
	}
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
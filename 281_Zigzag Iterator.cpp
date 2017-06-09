class ZigzagIterator {
private: queue<pair<vector<int>::iterator, vector<int>::iterator>> piterator;
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		if (v1.size() > 0)
			piterator.push(make_pair(v1.begin(), v1.end()));
		if (v2.size() > 0)
			piterator.push(make_pair(v2.begin(), v2.end()));
	}

	int next() {
		auto nextIter = piterator.front();
		piterator.pop();
		int res = *(nextIter.first);
		if (++ (nextIter.first) != nextIter.second)
			piterator.push(nextIter);
		return res;
	}

	bool hasNext() {
		return !piterator.empty();
	}
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

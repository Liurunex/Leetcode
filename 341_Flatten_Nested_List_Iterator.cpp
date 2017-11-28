class NestedIterator {
private:
	queue<int> stored;
	void push_all(NestedInteger nestitem) {
		if (nestitem.isInteger()) {
			//cout << nestitem.getInteger() << endl;
			stored.push(nestitem.getInteger());
			return;
		}
		vector<NestedInteger> next = nestitem.getList();
		for (NestedInteger nextitem:next) {
			push_all(nextitem);
		}
	}

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
    	for (NestedInteger nestitem:nestedList)
    		push_all(nestitem);
    }

    int next() {
        int res = stored.front();
        stored.pop();
        return res;
    }

    bool hasNext() {
        return stored.size() != 0;
    }
};

/* the idea: DFS (Recursion) + queue output. We use a queue to store all integers,
 * and preposessing the nested list by recursive DFS calling, straightforward
 */
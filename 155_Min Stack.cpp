class MinStack {
private:
    vector<int> mystack;
    vector<int> allmin;
public:
    /** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		mystack.push_back(x);
		if (allmin.empty() || allmin[allmin.size()-1] >= x)
			allmin.push_back(x);
	}

	void pop() {
		if (mystack[mystack.size()-1] == allmin[allmin.size()-1])
			allmin.pop_back();
		mystack.pop_back();
	}

	int top() {
		return mystack[mystack.size()-1];
	}

	int getMin() {
		return allmin[allmin.size()-1];
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

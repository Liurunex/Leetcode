class MyStack {
private: 
	queue<int> stlqueue;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		stlqueue.push(x);
		for (int i = 0; i < stlqueue.size()-1; ++ i) {
			int tem = stlqueue.front();
			stlqueue.pop();
			stlqueue.push(tem);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int tem = stlqueue.front();
		stlqueue.pop();
		return tem;
	}

	/** Get the top element. */
	int top() {
		return stlqueue.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return stlqueue.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
/* it's different to stack implememnt queue, do not rely on recursion method to solve it, directly use iterative way */

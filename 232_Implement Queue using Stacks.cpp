class MyQueue {
public:
    stack<int> mystack;
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!mystack.empty()) {
            mystack.push(x);
            return;
        }
        int tem = mystack.top();
        mystack.pop();
        push(x);
        mystack.push(tem);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
       int res = mystack.top(); 
       mystack.pop();
       return res;
    }
    
    /** Get the front element. */
    int peek() {
        return mystack.top(); 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mystack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
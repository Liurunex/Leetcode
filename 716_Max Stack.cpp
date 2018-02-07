class MaxStack {
private:
    stack<int> keeper;
    stack<int> maxhandler;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        keeper.push(x);
        if (!maxhandler.size() || maxhandler.top() <= x)
            maxhandler.push(x);
    }
    
    int pop() {
        int res = keeper.top();
        keeper.pop();
        if (res == maxhandler.top())
            maxhandler.pop();
        return res;
    }
    
    int top() {
        return keeper.top();
    }
    
    int peekMax() {
        return maxhandler.top();
    }
    
    int popMax() {
        int res = maxhandler.top();
        stack<int> tem;
        while (maxhandler.top() != keeper.top()) {
            tem.push(keeper.top());
            keeper.pop(); 
        }

        maxhandler.pop();
        keeper.pop();

        while (tem.size()) {
            this->push(tem.top());
            tem.pop();
        }
        return res;
    }
};
/* the idea: Two Stack. 一个栈存max，一个存数据：
 * push(): 对于Max stack, if only if max_stack empty or 栈顶元素不大于x，值入栈max stack
 * pop(): 只有当max stack 栈顶值 == 要pop的元素，max stack pop
 * popMax(): 先把stack中到max_stack栈顶值的元素push 到一个tem stack中，这样是为了维护那些元素中可能
 * 存在的second-max值，然后把这些值调用push()入栈
 *  */

class MaxStack {
private:
    list<int> dlist;
    map<int, list<list<int>::iterator>> maxcont;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        dlist.push_front(x);
        maxcont[x].push_front(dlist.begin());
    }
    
    int pop() {
        if (!dlist.size()) return -1;
        int target = dlist.front();
        maxcont[target].pop_front();
        if (!maxcont[target].size())
            maxcont.erase(target);
        dlist.pop_front();
        return target;
    }
    
    int top() {
        return dlist.front();
    }
    
    int peekMax() {
        return maxcont.rbegin()->first;
    }
    
    int popMax() {
        auto target = maxcont.rbegin()->second.front();
        int res = *target;
        maxcont.rbegin()->second.pop_front();
        if (!maxcont.rbegin()->second.size())
            maxcont.erase(res);
        dlist.erase(target);
        return res;
    }
};
/* the idea: double-linked list + map tree. 利用double-linked list的O(1)特性，然后
 * 利用map的sorted by key的性质，每一个key映射到一个iterator的container*/
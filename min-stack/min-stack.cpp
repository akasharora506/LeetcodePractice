class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    multiset<int> dic;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        dic.insert(x);
    }
    
    void pop() {
        dic.erase(dic.find(s.top()));
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *dic.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
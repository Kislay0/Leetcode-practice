class MinStack {
private:
    stack<int> st, mst;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        mst.push(min(val,(mst.empty() ? INT_MAX : mst.top())));
    }
    
    void pop() {
        mst.pop();
        st.pop();
    }
    
    int top() {
        return st.empty() ? -1 : st.top();
    }
    
    int getMin() {
        return mst.empty() ? -1 : mst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
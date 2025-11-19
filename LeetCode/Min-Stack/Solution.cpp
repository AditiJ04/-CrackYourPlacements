class MinStack {
    stack<pair<int,int>>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int Min;
        if(st.empty())
        {
            Min=val;
        }
        else
        {
            Min=min(st.top().second,val);
        }
        st.push({val,Min});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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
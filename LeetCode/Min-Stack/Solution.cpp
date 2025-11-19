class MinStack {
public:
    
    stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int mn=INT_MAX;

        vector<int>ans;
        while(!st.empty())
        {
            mn=min(mn,st.top());
            ans.push_back(st.top());
            st.pop();
        }

        for(int i=ans.size()-1;i>=0;i--)
        {
            st.push(ans[i]);
        }
        return mn;
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
class Solution {
public:

    int get(char c)
    {
        if(c=='(') return 1;
        if(c=='{') return 2;
        if(c=='[') return 3;
        if(c==')') return -1;
        if(c=='}') return -2;
        return -3;
    }
    bool isValid(string s) {
        int n=s.size();

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            int val=get(s[i]);
            if(val>0) st.push(val);
            else if( !st.empty() && abs(val)==st.top())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }

        if(!st.empty()) return false;
        return true;
    }
};
class Solution {
public:

    int get(string str,int a,int b)
    {
        if(str=="+")
        {
            return a+b;
        }
        else if(str=="*")
        {
            return a*b;
        }
        else if(str=="/")
        {
            return a/b;
        }
        
        return a-b;
    }

    bool check(string str)
    {
        if(str=="+" || str=="-" || str=="*" || str=="/") return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        int n=tokens.size();

        for(int i=0;i<n;i++)
        {
            if(check(tokens[i]))
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();

                int num=get(tokens[i],a,b);
                st.push(num);
            }
            else
            {
                int dig=stoi(tokens[i]);
                st.push(dig);
            }
        }

        return st.top();
    }
};
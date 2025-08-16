class Solution {
public:
    int generateP(char ch)
    {
        if(ch=='(')
        {
            return 1;
        }

        if(ch=='[')
        {
            return 2;
        }

        if(ch=='{')
        {
            return 3;
        }


        if(ch==')')
        {
            return -1;
        }

        if(ch==']')
        {
            return -2;
        }

        return -3;
    }
    bool isValid(string s) {
        stack<int>st;

        int n=s.size();

        for(int i=0;i<n;i++)
        {

            if(st.empty())
            {
                int val=generateP(s[i]);
                if(val<0)
                {
                    return false;
                }
                st.push(val);
            }

            else 
            {
                int val=generateP(s[i]);

                if(st.top()>0 && val>0)
                {
                    st.push(val);
                }
                else 
                {
                    if(st.top()==abs(val))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(!st.empty())
        {
            return false;
        }
        return true;
    }
};
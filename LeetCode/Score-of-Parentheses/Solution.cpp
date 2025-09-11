class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(-1);
            }
            else if(s[i]==')')
            {
                if(st.top()!=-1)
                {
                   int sum=0;

                   while(!st.empty() && st.top()!=-1)
                   {
                    sum+=st.top();
                    st.pop();
                   }
                   st.pop();
                   st.push(2*sum);
                }
                else
                {
                    st.pop();
                    st.push(1);
                }
            }
        }
        int ans=0;

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};
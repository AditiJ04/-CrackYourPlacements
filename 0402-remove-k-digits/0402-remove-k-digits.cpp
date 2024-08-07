class Solution {
public:
    string removeKdigits(string num, int k) {

        string ans="";

        stack<int>st;
        int n=num.length();

        if(n==k)
        {
            return "0";
        }

        for(int i=0;i<n;i++)
        {
                while(!st.empty() && st.top()>num[i] && k!=0)
                {
                    k--;
                    st.pop();
                }
              
              st.push(num[i]);

              if(st.size()==1 && num[i]=='0')
              {
                st.pop();
              }
        }

        while(k && !st.empty())
        {
            --k;
            st.pop();
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        int m=ans.size();

        if(m==0)
        {
            return "0";
        }
        
        reverse(ans.begin(),ans.end());

        

        return ans;
    }
};
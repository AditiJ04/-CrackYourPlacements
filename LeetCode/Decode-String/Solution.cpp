class Solution {
public:
    bool checkNumber(string &s)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(!isdigit(s[i])) return false;
        }

        return true;
    }
    string decodeString(string s) {
        stack<char>st;
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if(s[i]==']')
            {
                string ans="";
                while(st.top()!='[')
                {
                    ans+=st.top();
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
        
                st.pop();

                string numstr="";

                while(!st.empty() && isdigit(st.top()))
                {
                    numstr=st.top()+numstr;
                    st.pop();
                }
                int val=stoi(numstr);
                string res="";
                while(val!=0)
                {
                    res+=ans;
                    val--;
                }
                for(int i=0;i<res.size();i++) st.push(res[i]);
                continue;
            }

            st.push(s[i]);
        }

        string fans="";

        while(!st.empty())
        {
            fans+=st.top();
            st.pop();
        }

        reverse(fans.begin(),fans.end());
        return fans;
    }
};
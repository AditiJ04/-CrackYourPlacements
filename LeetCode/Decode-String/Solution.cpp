class Solution {
public:
    string decodeString(string s) {
        int n=s.size();

        stack<pair<int,string>>st;

        int currnum=0;
        string currstr="";
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                currnum=currnum*10+s[i]-'0';
            }
            else if(isalpha(s[i]))
            {
                currstr.push_back(s[i]);
            }
            else if(s[i]=='[')
            {
                st.push({currnum,currstr});
                currnum=0;
                currstr="";
            }
        
            else if(s[i]==']')
            {
                string prevstr=st.top().second;
                for(int i=0;i<st.top().first;i++)
                {
                    prevstr+=currstr;
                }
                st.pop();
                currstr=prevstr;
            }
        }
        return currstr;
    }
};
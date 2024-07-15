class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#' && !st1.empty())
            {
                st1.pop();
            }
            else if(s[i]=='#')
            {
                continue;
            }
            else
            {
                st1.push(s[i]);
            }
        }
        s="";
        while(!st1.empty())
        {
            s+=st1.top();
            st1.pop();
        }

        for(int i=0;i<t.length();i++)
        {
            if(t[i]=='#' && !st2.empty())
            {
                st2.pop();
            }
            else if(t[i]=='#')
            {
                continue;
            }
            else
            {
                st2.push(t[i]);
            }
        }
        t="";

         while(!st2.empty())
        {
            t+=st2.top();
            st2.pop();
        }

        if(s==t)
        {
            return true;
        }
        return false;
    }
};
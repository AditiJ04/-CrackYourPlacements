class Solution {
public:
    int getChar(char c)
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

        stack<char>st;

        for(int i=0;i<n;i++)
        {
            int num=getChar(s[i]);
            if(st.empty() && num<0) return false;
            if(num>0 || st.empty()) st.push(s[i]);
            else
            {
                if(abs(num)==getChar(st.top())) st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;

        return false;
    }
};
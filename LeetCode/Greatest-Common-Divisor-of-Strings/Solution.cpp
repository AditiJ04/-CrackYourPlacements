class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();

        if(n==m)
        {
            if(str1!=str2)
            {
                return "";
            }
        }

        if(m>n)
        {
            swap(n,m);
        }

        int GCD=gcd(n,m);

        string str=str1.substr(0,GCD);

        auto check=[&](string s,string t)
        {
            string ans="";
            int sz=s.size()/t.size();
            for(int i=0;i<sz;i++)
            {
                ans+=t;
            }

            return ans==s;
        };

        if(check(str1,str) && check(str2,str))
        {
            return str;
        }

        return "";
    }
};
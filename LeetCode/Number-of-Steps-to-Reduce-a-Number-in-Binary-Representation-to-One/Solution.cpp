1class Solution {
2public:
3    int numSteps(string s) {
4        int n=s.size();
5        int ans=n-1,carry=0;
6
7        for(int i=n-1;i>0;i--)
8        {
9            if(s[i]-'0'+carry==1)
10            {
11                ans++;
12                carry=1;
13            }
14        }
15        return ans+carry;
16    }
17};
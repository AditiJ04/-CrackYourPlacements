1class Solution {
2public:
3    bool checkOnesSegment(string s) {
4        int n=s.size();
5
6        int c1=0;
7        int ans=0;
8
9        for(int i=0;i<n;i++)
10        {
11            if(s[i]=='1')
12            {
13                c1=1;
14            }
15            else
16            {
17                ans+=c1;
18                c1=0;
19            }
20        }
21        ans+=c1;
22
23        if(ans==1) return true;
24
25        return false;
26    }
27};
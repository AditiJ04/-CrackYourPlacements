1class Solution {
2public:
3    int minimumDeletions(string s) {
4        int n=s.size();
5        int cnt_b=0;
6
7        int ans=0;
8
9        for(int i=0;i<n;i++)
10        {
11            if(s[i]=='a')
12            {
13                if(cnt_b>0)
14                {
15                    ans++;
16                    cnt_b--;
17                }
18            }
19            else
20            {
21                cnt_b++;
22            }
23        }
24
25        return ans;
26    }
27};
1class Solution {
2public:
3    int beautySum(string s) {
4        int res=0;
5    
6        for(int i=0;i<s.length();i++)
7        {
8            unordered_map<char,int>mp;
9            for(int j=i;j<s.length();j++)
10            {
11                mp[s[j]]++;
12
13                if(mp.size()==1)
14                {
15                    res+=0;
16                }
17
18                else
19                {
20                    int Min=INT_MAX;
21                    int Max=INT_MIN;
22
23                    for(auto it:mp)
24                    {
25                        Min=min(Min,it.second);
26                        Max=max(Max,it.second);
27                    }
28                    res=res+Max-Min;                
29                }
30            }
31        }
32        return res;
33    }
34};
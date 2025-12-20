1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n=strs.size();
5        int m=strs[0].size();
6        int cnt=0;
7        for(int i=0;i<m;i++)
8        {
9            int idx=i;
10            string prev="";
11            for(int j=0;j<n;j++)
12            {
13                if(!prev.empty() && prev[idx]>strs[j][idx]) 
14                {
15                    cnt++;
16                    break;
17                }
18                prev=strs[j];
19            }
20        }
21
22        return cnt;
23    }
24};
25
26// rrjk
27// furt
28// guzm
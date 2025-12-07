1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int r=0,c=0;
5
6        int n=moves.size();
7
8        for(int i=0;i<n;i++)
9        {
10            if(moves[i]=='U')
11            {
12                r=r-1;
13            }
14            else if(moves[i]=='D')
15            {
16                r=r+1;
17            }
18            else if(moves[i]=='L')
19            {
20                c=c-1;
21            }
22            else
23            {
24                c=c+1;
25            }
26        }
27
28        return (r==0 && c==0);
29    }
30};
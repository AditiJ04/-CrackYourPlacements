1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int n=moves.size();
5
6        int xi=0;
7        int yi=0;
8        for(int i=0;i<n;i++)
9        {
10            if(moves[i]=='U')
11            {
12                yi-=1;
13            }
14            else if(moves[i]=='D')
15            {
16                yi+=1;
17            }
18
19            else if(moves[i]=='L')
20            {
21                xi-=1;
22            }
23
24            else if(moves[i]=='R')
25            {
26                xi+=1;
27            }
28        }
29
30        if(xi==0 && yi==0)
31        {
32            return true;
33        }
34
35        return false;
36    }
37};
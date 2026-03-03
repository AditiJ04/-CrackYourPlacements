1class Solution {
2public:
3    string mergeCharacters(string s, int k) {
4        
5        string str=s;
6
7        int m=str.size();
8        for(int i=0;i<m;)
9        {
10            char c=str[i];
11            int flg=1;
12            for(int j=i+1;j<=i+k && j<m;j++)
13            {
14                char nc=str[j];
15
16                if(nc==c)
17                {
18                    str.erase(j,1);
19                    flg=0;
20                    break;
21                }
22            }
23            if(flg) i++;
24            else i=0;
25            m=str.size();
26        }
27
28        return str;
29    }
30};
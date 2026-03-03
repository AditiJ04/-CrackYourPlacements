1class Solution {
2public:
3    string mergeCharacters(string s, int k) {
4
5        string str = s;
6
7        int m = str.size();
8        for (int i = 0; i < m;) {
9            char c = str[i];
10            int flg = 1;
11            for (int j = i + 1; j < m; j++) {
12                if (j - i > k)
13                    break;
14                char nc = str[j];
15
16                if (nc == c) {
17                    str.erase(j, 1);
18                    flg = 0;
19                    break;
20                }
21            }
22            if (flg)
23                i++;
24            else i=0;
25            m = str.size();
26        }
27
28        return str;
29    }
30};
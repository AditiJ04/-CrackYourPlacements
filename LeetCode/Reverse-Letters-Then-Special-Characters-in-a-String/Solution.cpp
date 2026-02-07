1class Solution {
2public:
3    string reverseByType(string s) {
4        int n=s.size();
5        int i=0,j=n-1;
6
7        while(i<=j)
8        {
9            if(isalpha(s[i]) && isalpha(s[j]))
10            {
11                swap(s[i],s[j]);
12                i++;
13                j--;
14                continue;
15            }
16            if(!isalpha(s[i]))
17            {
18                i++;
19            }
20            if(!isalpha(s[j]))
21            {
22                j--;
23            }
24        }
25
26        i=0,j=n-1;
27
28        while(i<=j)
29        {
30            if(!isalpha(s[i]) && !isalpha(s[j]))
31            {
32                swap(s[i],s[j]);
33                i++;
34                j--;
35                continue;
36            }
37            if(isalpha(s[i]))
38            {
39                i++;
40            }
41            if(isalpha(s[j]))
42            {
43                j--;
44            }
45        }
46
47        return s;
48    }
49};
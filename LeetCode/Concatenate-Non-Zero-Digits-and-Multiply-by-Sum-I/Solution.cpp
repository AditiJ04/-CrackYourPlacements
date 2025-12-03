1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        long long sum=0;
5        long long mul=1;
6
7        long long num=0;
8
9        string str=to_string(n);
10
11        for(int i=0;i<str.size();i++)
12        {
13            if(str[i]!='0')
14            {
15                num*=10;
16                num+=str[i]-'0';
17                sum+=str[i]-'0';
18            }
19        }
20        
21        mul=sum*num;
22
23        return mul;
24    }
25};
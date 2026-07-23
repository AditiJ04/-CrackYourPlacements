1class Solution {
2public:
3    int climbStairs(int n) {
4        if(n==0 || n==1 || n==2) return n;
5
6        int a=1,b=2;
7
8        for(int i=3;i<=n;i++)
9        {
10            int c=a+b;
11            a=b;
12            b=c;
13        }
14
15        return b;
16    }
17};
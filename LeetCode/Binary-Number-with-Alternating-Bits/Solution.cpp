1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4        int prev=-1;
5        while(n!=0)
6        {
7            int r=n%2;
8            if(prev!=-1 && r==prev) return false;
9            prev=r;
10            n/=2;
11        }
12
13        return true;
14    }
15};
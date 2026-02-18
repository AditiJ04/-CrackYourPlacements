1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4        long long x=n ^(n>>1);
5        return (x & (x+1))==0;
6    }
7};
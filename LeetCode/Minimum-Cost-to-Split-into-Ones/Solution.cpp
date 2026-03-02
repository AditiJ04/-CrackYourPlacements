1class Solution {
2public:
3    int minCost(int n) {
4        if(n==1) return 0;
5
6        return 1*(n-1)+minCost(n-1);
7    }
8};
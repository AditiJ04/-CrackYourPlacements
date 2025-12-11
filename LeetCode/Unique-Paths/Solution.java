1class Solution {
2    int M,N;
3    public int possiblePaths(int r,int c,int [][]arr,int [][]dp)
4    {
5        if(r<0 || c<0 || r==M || c==N) return 0;
6        if(r==M-1 && c==N-1) 
7        {
8            return 1;
9        }
10        
11        if(dp[r][c]!=-1) return dp[r][c];
12        int v1=possiblePaths(r+1,c,arr,dp);
13        int v2=possiblePaths(r,c+1,arr,dp);
14
15        return dp[r][c]=v1+v2;
16    }
17    public int uniquePaths(int m, int n) {
18        
19        M=m;
20        N=n;
21        int [][]arr=new int[m][n];
22        int [][]dp=new int[m][n];
23
24        for(int i=0;i<m;i++)
25        {
26            for(int j=0;j<n;j++)
27            {
28                dp[i][j]=-1;
29            }
30        }
31
32        return possiblePaths(0,0,arr,dp);
33    }
34}
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)
        {
            return -1;
        }
        
        queue<pair<int,int>>que;
        
        int delrow[4]={0,-1,0,+1};
        int delcol[4]={-1,0,+1,0};
        
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        
        que.push({0,0});
        dist[0][0]=0;
        while(!que.empty())
        {
            auto it=que.front();
            
            que.pop();
            
            int r=it.first;
            int c=it.second;
            
            if(r==X && c==Y)
            {
                return dist[r][c];
            }
            
            for(int i=0;i<4;i++)
            {
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
                if(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]==1)
                {
                    if(dist[nr][nc]>1+dist[r][c])
                    {
                        dist[nr][nc]=1+dist[r][c];
                        que.push({nr,nc});
                    }
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
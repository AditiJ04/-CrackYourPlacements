class Solution {
public:
    int n;

    int row[8]={0,-1,0,1,-1,-1,1,1};
    int col[8]={-1,0,1,0,-1,1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1]==1)
            return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        
        dist[0][0]=1;

        pq.push({1,{0,0}});

        while(!pq.empty())
        {
            int dis=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==n-1) return dis;
            for(int k=0;k<8;k++)
            {
                int i=r+row[k];
                int j=c+col[k];

                if(i<0 || j<0 || i>=n || j>=n || grid[i][j]) continue;

                if(dis+1<dist[i][j])
                {
                    dist[i][j]=dis+1;
                    pq.push({dist[i][j],{i,j}});
                }
            }
        }

        return -1;
    }
};
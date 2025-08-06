class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>que;

        int fresh=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                else if(grid[i][j]==2)
                {
                    que.push({i,j});
                }
            }
        }

        if(fresh==0)
        {
            return 0;
        }

        int t=0;
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};

        while(!que.empty())
        {
            int sz=que.size();

          //  t++;

            for(int i=0;i<sz;i++)
            {
                auto [x,y]=que.front();
                que.pop();

                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];


                    if(nx>=0 && nx<n  && ny>=0 && ny<m && grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        fresh--;
                        que.push({nx,ny});
                    }
                }
            }

            if(!que.empty())
            {
            t++;
            }
        }

        return fresh==0?t:-1;
    }
};
//(i,j)
//{0,-1,0,1},{-1,0,1,0}
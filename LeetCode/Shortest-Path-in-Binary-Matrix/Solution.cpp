class Solution {
public:
    
   vector<vector<int>>dirs={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(m==0 || n==0 || grid[0][0]==1)
        {
            return -1;
        }

       // int row[]={0,-1,-1,-1,0,1,1,1};
        //int col[]={-1,-1,0,1,1,1,0,-1};

        auto issafe=[&](int x,int y)
        {
            if(x>=0 && x<n && y>=0 && y<m)
            {
                return true;
            }

            return false;
        };
        queue<pair<int,int>>que;
        que.push({0,0});

        grid[0][0]=1;

        int lev=0;

        while(!que.empty())
        {
            int N=que.size();

            while(N--)
            {
                auto curr=que.front();
                que.pop();

                int x=curr.first;
                int y=curr.second;

                if(x==n-1 && y==m-1)
                {
                    return lev+1;
                }

                for(auto dir:dirs)
                {
                    int x_=x+dir[0];
                    int y_=y+dir[1];

                    if(issafe(x_,y_) && grid[x_][y_]==0)
                    {
                        que.push({x_,y_});
                        grid[x_][y_]=1;
                    }
                }

            }

            lev++;
        }

        return -1;
    }
};
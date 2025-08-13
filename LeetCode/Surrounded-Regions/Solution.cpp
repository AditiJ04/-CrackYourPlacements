class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis)
    {
        int n=board.size();
        int m=board[0].size();

        vis[i][j]=1;

        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};

        for(int k=0;k<4;k++)
        {
            int nr=i+row[k];
            int nc=j+col[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && board[nr][nc]=='O')
            {
                dfs(nr,nc,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        //checking for row
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O' && vis[0][i]==0)
            {
                dfs(0,i,board,vis);
            }
            if(board[n-1][i]=='O' && vis[n-1][i]==0)
            {
                dfs(n-1,i,board,vis);
            }
        }

         for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
            {
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]==0)
            {
                dfs(i,m-1,board,vis);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }

        //board;
    }
};
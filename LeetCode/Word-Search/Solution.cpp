class Solution {
public:

    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};

    int n,m;
    bool findWord(vector<vector<char>>&board,vector<vector<int>>&vis,string word,int idx,int i,int j)
    {
        if(i<0 || j<0 || i==n || j==m) return false;
        if(idx==word.size()) return true;

        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nr=i+row[k];
            int nc=j+col[k];

            if(nr<0 || nc<0 || nr==n || nc==m || vis[nr][nc]) continue;

            if(board[nr][nc]==word[idx])
            {
                if(findWord(board,vis,word,idx+1,nr,nc)) return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(findWord(board,vis,word,1,i,j)) return true;
                }
            }
        }

        return false;
    }
};
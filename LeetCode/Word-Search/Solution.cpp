class Solution {
public:
    bool Search(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis,string word,int idx)
    {
        int n=board.size();
        int m=board[0].size();

        if(idx==word.size())
        {
            return true;
        }

         if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || board[i][j] != word[idx])
        return false;

        vis[i][j]=1;

        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};

        for(int k=0;k<4;k++)
        {
            int nr=i+row[k];
            int nc=j+col[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m)
            {
                if(Search(nr,nc,board,vis,word,idx+1))
                {
                    return true;
                }
            }
        }

        vis[i][j]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        if(n==1 && word.size()==1)
        {
            if(board[0][0]==word[0])
            {
                return true;
            }

            return false;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                     vector<vector<int>>vis(n,vector<int>(m,0));
                    if(Search(i,j,board,vis,word,0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
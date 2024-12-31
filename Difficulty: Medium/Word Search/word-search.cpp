//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};
    
    bool Find(vector<vector<char>>&board,string word,vector<vector<int>>&vis,int r,int c,int idx)
    {
        int n=board.size();
        int m=board[0].size();
        
        if(idx==word.size())
        {
            return true;
        }
        
        if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || board[r][c] != word[idx]) {
        return false;  // Out of bounds or cell already visited or mismatch
    }
        
        vis[r][c]=1;
        
        int nr,nc;
        
        for(int i=0;i<4;i++)
        {
            nr=r+row[i];
            nc=c+col[i];
            
            if(Find(board,word,vis,nr,nc,idx+1))
            {
                return true;
            }
        }
        
        vis[r][c]=0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    if(Find(board,word,vis,i,j,0))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
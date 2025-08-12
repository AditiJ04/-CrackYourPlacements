class Solution {
public:
    
    void dfs(vector<vector<int>>&image,int sr,int sc,int oricolor,int color)
    {
        int n=image.size();
        int m=image[0].size();

        image[sr][sc]=color;

        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};

        for(int i=0;i<4;i++)
        {
            int nr=sr+row[i];
            int nc=sc+col[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==oricolor) 
            {
                dfs(image,nr,nc,oricolor,color);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
      
        int oricolor=image[sr][sc];
         if (oricolor != color)
         {
        dfs(image, sr, sc, oricolor, color);
         }

        return image;
    }
};
class Solution {
public:

    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};

    void fillImage(int sr,int sc,int color,vector<vector<int>>&image,int oricolor)
    {
        int n=image.size();
        int m=image[0].size();

        image[sr][sc]=color;

        for(int i=0;i<4;i++)
        {
            int nr=sr+row[i];
            int nc=sc+col[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==oricolor)
            {
                fillImage(nr,nc,color,image,oricolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc]==color) return image;
        fillImage(sr,sc,color,image,image[sr][sc]);

        return image;
    }
};
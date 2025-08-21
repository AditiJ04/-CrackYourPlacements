class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int>ans;

        vector<vector<int>>spiral(n,vector<int>(n,0));
        for(int i=1;i<=(n*n);i++)
        {
            ans.push_back(i);
        }

        int top=0,bottom=n-1,left=0,right=n-1;
        int i=0;

        while(top<=bottom && left<=right)
        {
            for(int k=left;k<=right;k++)
            {
                spiral[top][k]=ans[i];
                i++;
            }
            top++;

            for(int k=top;k<=bottom;k++)
            {
                spiral[k][right]=ans[i];
                i++;
            }
            right--;

            if(left<=right)
            {
               for(int k=right;k>=left;k--)
               {
                spiral[bottom][k]=ans[i];
                i++;
               }
            }

            bottom--;

            if(bottom>=top)
            {
                for(int k=bottom;k>=top;k--)
                {
                spiral[k][left]=ans[i];
                i++;
                }
            }
            left++;
        }

        return spiral;
    }
};
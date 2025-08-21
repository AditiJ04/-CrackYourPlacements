class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>ans;

        int tr=0,br=n-1,fc=0,lc=m-1;

        while(tr<=br && fc<=lc)
        {
            for(int k=fc;k<=lc;k++)
            {
                ans.push_back(matrix[tr][k]);
            }
            tr++;

            for(int k=tr;k<=br;k++)
            {
                ans.push_back(matrix[k][lc]);
            }
            lc--;

            if(tr<=br)
            {
            for(int k=lc;k>=fc;k--)
            {
                ans.push_back(matrix[br][k]);
            }
            }
            br--;

            if(fc<=lc)
            {
                for(int k=br;k>=tr;k--)
                {
                    ans.push_back(matrix[k][fc]);
                }
            }
            fc++;
        }

        return ans;
    }
};
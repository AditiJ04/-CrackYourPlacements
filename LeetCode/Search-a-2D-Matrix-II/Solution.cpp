class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int l=0;
        int h=m-1;

        while(l<n && h>=0)
        {
            if(matrix[l][h]==target)
            {
                return true;
            }
            else if(matrix[l][h]>target)
            {
                h--;
            }
            else
            {
                l++;
            }
        }

        return false;
    }
};
class Solution {
public:
    int findUB(vector<int>&arr,int m,int num)
    {
        int l=0;
        int h=m-1;
        int ans=m;

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(arr[mid]>num)
            {
                ans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        if(n==1 && m==1)
        {
            if(matrix[0][0]==target)
            {
                return true;
            }
        }

        for(int i=0;i<n;i++)
        {
            int num=findUB(matrix[i],m,target-1);

            if(num<m && matrix[i][num]==target)
            {
                return true;
            }
        }

        return false;
    }
};
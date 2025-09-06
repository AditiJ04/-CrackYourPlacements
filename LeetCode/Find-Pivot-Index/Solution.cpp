class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return 0;

        vector<int>preLeft(n,0);
        vector<int>preRight(n,0);

        preLeft[0]=nums[0];
        preRight[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            preLeft[i]=preLeft[i-1]+nums[i];
        }

        for(int i=n-2;i>=0;i--)
        {
            preRight[i]=preRight[i+1]+nums[i];
        }

        if(preRight[1]==0) return 0;
        for(int i=1;i<n-1;i++)
        {
            if(preLeft[i-1]==preRight[i+1])
            {
                return i;
            }
        }
        if(preLeft[n-2]==0) return n-1;

        return -1;
    }
};
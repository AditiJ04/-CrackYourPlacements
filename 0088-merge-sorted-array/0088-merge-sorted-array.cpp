class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;

        vector<int>ans(m,0);

        for(int k=0;k<m;k++)
        {
            ans[k]=nums1[k];
        }
        int l=0;
        while(i<m && j<n)
        {
            if(ans[i]<=nums2[j])
            {
                nums1[l]=ans[i];
                i++;
                l++;
            }
            else if(nums2[j]<=ans[i])
            {
                nums1[l]=nums2[j];
                j++;
                l++;
            }
        }

        while(j<n)
        {
            nums1[l]=nums2[j];
            l++;
            j++;
        }
        while(i<m)
        {
            nums1[l]=ans[i];
            i++;
            l++;
        }
    }
};
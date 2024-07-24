class Solution {
public:
    void merge(vector<int>&nums,int l,int mid,int h,int &cnt)
    {
        int j=mid+1;

        for(int i=l;i<=mid;i++)
        {
            while(j<=h && nums[i]>2*(long long)nums[j])
            {
                j++;
            }
            cnt+=j-(mid+1);
        }

        int s=h-l+1;

        vector<int>tmp(s,0);

        int left=l,right=mid+1,k=0;

        while(left<=mid && right<=h)
        {
            if(nums[left]<nums[right])
            {
                tmp[k++]=nums[left++];
            }
            else
            {
                tmp[k++]=nums[right++];
            }
        }

        while(left<=mid)
        {
            tmp[k++]=nums[left++];
        }

        while(right<=h)
        {
            tmp[k++]=nums[right++];
        }

        int m=0;

        for(int i=l;i<=h;i++)
        {
            nums[i]=tmp[m++];
        }

    }
    void mergeSort(vector<int>&nums,int l,int h,int &cnt)
    {
        if(l<h)
        {
            int mid=(l+h)/2;
            mergeSort(nums,l,mid,cnt);
            mergeSort(nums,mid+1,h,cnt);
            merge(nums,l,mid,h,cnt);
        }
    }
    int reversePairs(vector<int>& nums) {
        int cnt=0;

        mergeSort(nums,0,nums.size()-1,cnt);

        return cnt;
    }
};
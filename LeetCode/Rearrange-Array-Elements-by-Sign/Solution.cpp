class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();

        vector<int>pos;
        vector<int>neg;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }

        int i=0,j=0,k=0;
        while(i<pos.size() && j<neg.size())
        {
            nums[k++]=pos[i++];
            nums[k++]=neg[j++];
        }

        while(i<pos.size())
        {
            nums[k++]=pos[i++];
        }
        while(j<neg.size())
        {
            nums[k++]=neg[j++];
        }

        return nums;
    }
};
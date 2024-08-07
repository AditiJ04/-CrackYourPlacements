class Solution {
public:
    void Permute(vector<int>nums,vector<vector<int>>&ans,int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }

        else
        {
        
            for(int j=idx;j<nums.size();j++)
            {
                if(j==idx || nums[j]!=nums[idx])
                {
                swap(nums[j],nums[idx]);
                Permute(nums,ans,idx+1);
                }

            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());
        Permute(nums,ans,0);

        return ans;
    }
};
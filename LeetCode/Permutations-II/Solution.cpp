class Solution {
public:
    vector<vector<int>>ans;
    void findPerm(vector<int>nums,int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i==idx || nums[i]!=nums[idx])
            {
            swap(nums[i],nums[idx]);
            findPerm(nums,idx+1);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        findPerm(nums,0);

        return ans;
    }
};
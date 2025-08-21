class Solution {
public:
    void permut(vector<int>nums,vector<vector<int>>&ans,int start)
    {
        if(start==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        else
        {
            for(int j=start;j<nums.size();j++)
            {
                if(j==start || nums[j]!=nums[start])
                {
                    swap(nums[j],nums[start]);
                    permut(nums,ans,start+1);
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;

        permut(nums,ans,0);

        return ans;
    }
};
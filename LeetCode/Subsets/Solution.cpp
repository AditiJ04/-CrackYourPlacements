class Solution {
public:
    void Subsets(vector<int>&nums,vector<int>&v,vector<vector<int>>&ans,int idx)
    {
        ans.push_back(v);

        for(int i=idx;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            Subsets(nums,v,ans,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {

     //   sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        Subsets(nums,v,ans,0);

        return ans;
    }
};
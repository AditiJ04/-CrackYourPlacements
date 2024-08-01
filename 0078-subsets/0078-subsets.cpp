class Solution {
public:
    void print(vector<vector<int>>&ans,vector<int>&v,vector<int>&nums,int i)
    {
        ans.push_back(v);

        for(int j=i;j<nums.size();j++)
        {
            v.push_back(nums[j]);
            print(ans,v,nums,j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;

        print(ans,v,nums,0);

        return ans;
    }
};
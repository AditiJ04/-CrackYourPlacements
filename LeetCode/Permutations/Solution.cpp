class Solution {
public:

    set<vector<int>>ans;

    void findPermutation(vector<int>&nums,int idx)
    {
        if(idx==nums.size()) return;

        for(int i=0;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            ans.insert(nums);
            findPermutation(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();

        findPermutation(nums,0);

        vector<vector<int>>v(ans.begin(),ans.end());

        return v;
    }
};
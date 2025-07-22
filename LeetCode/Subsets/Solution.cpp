class Solution {
public:

    vector<vector<int>>ans;
    void Subset(vector<int>&nums,vector<int>&arr,int idx)
    {
      //  int n=nums.size();
        ans.push_back(arr);

        if(idx==nums.size())
        {
            return;
        }

        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1])
            {
                continue;
            }
            arr.push_back(nums[i]);
            Subset(nums,arr,i+1);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
     
        int n=nums.size();

        vector<int>arr;

        sort(nums.begin(),nums.end());
        Subset(nums,arr,0);

        return ans;
    }
};
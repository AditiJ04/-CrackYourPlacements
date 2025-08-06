class Solution {
public:
    set<vector<int>>st;
    void findSubset(vector<int>&nums,vector<int>&v,int idx)
    {
        st.insert(v);
        if(idx==nums.size()) return;

        v.push_back(nums[idx]);
        findSubset(nums,v,idx+1);
        v.pop_back();
        findSubset(nums,v,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>v;
        findSubset(nums,v,0);

        ans.assign(st.begin(),st.end());
        return ans;
    }
};
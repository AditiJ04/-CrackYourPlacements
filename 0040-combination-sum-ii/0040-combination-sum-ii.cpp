class Solution {
public:

    void Combination(vector<int>&candidates,int target,vector<int>&v,vector<vector<int>>&ans,int idx)
    {
        if(target<0)
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
            {
                continue;
            }
            if(candidates[i]>target)
            {
                break;
            }
            v.push_back(candidates[i]);
            Combination(candidates,target-candidates[i],v,ans,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        int n=candidates.size();

        vector<vector<int>>ans;
        vector<int>v;

        Combination(candidates,target,v,ans,0);

        return ans;
    }
};
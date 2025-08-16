class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();

        sort(nums.begin(),nums.end());

        set<vector<int>>st;

        vector<vector<int>>ans;

        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];

                if(sum==0)
                {
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
            }
        }

        for(auto it:st)
        {
            ans.push_back(it);
        }

        return ans;
    }
};
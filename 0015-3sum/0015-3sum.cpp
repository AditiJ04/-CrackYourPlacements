class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int t=0,n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        vector<vector<int>>output;

        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==t)
                {
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum<t)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        for(auto c:s)
        {
            output.push_back(c);
        }

        return output;
    }
};
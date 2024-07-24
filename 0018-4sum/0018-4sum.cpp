class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<int>v;
        set<vector<int>>set;
        vector<vector<int>>vf;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j,k;

        while(i<n)
        {
            j=i+1;
            while(j<n)
            {
                k=j+1;
                int s=n-1;
                while(k<s)
                {
                    long long int sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[s];
                    if(sum==target)
                    {
                       set.insert({nums[i],nums[j],nums[k],nums[s]});

                        k++;
                        s--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        s--;
                    }
                }
                j++;
            }
            i++;
        }

        for(auto c:set)
        {
            vf.push_back(c);
        }
        return vf;
    }
};
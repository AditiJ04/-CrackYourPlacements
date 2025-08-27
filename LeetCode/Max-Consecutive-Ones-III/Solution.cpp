class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        int i=0;
        int j=0;

        int cnt=0;
        int mx=0;

        while(i<n)
        {
            if(nums[i]==0)
            {
                cnt++;
            }

            if(cnt<=k)
            {
                mx=max(mx,i-j+1);
            }

            else 
            {
                if(cnt>k)
                {
                    if(nums[j]==0)
                    {
                        cnt--;
                    }
                    j++;
                }
             //   mx=max(mx,i-j+1);
            }
            i++;
        }

        return mx;
    }
};
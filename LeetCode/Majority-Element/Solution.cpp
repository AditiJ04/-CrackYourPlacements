class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n=nums.size();
        int ans=nums[n-1];
        sort(nums.begin(),nums.end());

        int prev=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                int cnt=i-prev;

                if(cnt>ceil(n/2)) 
                {
                    return nums[i-1];
                }
                prev=i;
            }
        }
        if(n-prev>ceil(n/2)) return nums[n-1];

        return -1;
    }
};

// 2 2 2 3 3 3 3 
// 0 1 2 3 4 5 6
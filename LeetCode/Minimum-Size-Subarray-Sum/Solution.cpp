class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sub=INT_MAX;
        int n=nums.size();
        int sum=0;
        int i=0,j=0;
        while(i<n)
        {
           
            sum+=nums[i];
              //  cnt+=1;
                if(sum==target)
                {
                    sub=min(sub,i-j+1);
                }
                else if(sum>target)
                {
                    while(sum>=target && j<=i)
                    {
                        sub=min(sub,i-j+1);
                        sum-=nums[j];
                        j++;
                    }
                }
            i++;
        }
        
           if(sum>=target)
           {
                sub=min(sub,i-j+1);
           }
    if(sub==INT_MAX)
    {
        return 0;
    }
    return sub;
    }
};
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        queue<vector<int>> q;
        int n=nums.size();
        int m= multipliers.size();
        int ans=-1;

         q.push({1,nums[n-1]*multipliers[0],0,n-2,1});
         q.push({1,nums[0]*multipliers[0],1,n-1,1});


         while(!q.empty())
         {
            auto top=q.front();
            q.pop();
            int opr=top[0],val=top[1],st=top[2],end=top[3],ms=top[4];
             if(opr>=m)
             {
                ans=max(ans,val);
                continue;
             }
                    if(st>end)
                    continue;
             
                   q.push({opr+1,val+nums[end]*multipliers[ms],st,end-1,ms+1});
                   q.push({opr+1,val+nums[st]*multipliers[ms],st+1,end,ms+1});
             
         }
             return ans;
    }
};

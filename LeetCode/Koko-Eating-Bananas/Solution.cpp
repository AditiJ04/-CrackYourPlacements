class Solution {
public:
     long long findEatingSpeed(vector<int>&piles,int capacity)
    {
        long long cnt=0;

        for(int i=0;i<piles.size();i++)
        {
            cnt+=(piles[i]%capacity==0)?(piles[i]/capacity):(piles[i]/capacity)+1;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int l=1;
        int r=*max_element(piles.begin(),piles.end());

        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            long long cnt=findEatingSpeed(piles,mid);

            if(cnt<=h)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return ans;
    }
};
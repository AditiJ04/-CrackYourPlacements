class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int wl=n-k;
        int tsum=accumulate(cardPoints.begin(),cardPoints.end(),0);

        if(n==k) return tsum;

        int ans=0;

        int i=0,j=0;
        int sum=0;

        while(j<n)
        {
            sum+=cardPoints[j];
            if(j-i+1==wl)
            {
                ans=max(ans,tsum-sum);
                sum-=cardPoints[i];
                i++;
            }
            j++;
        }

        return ans;
    }
};
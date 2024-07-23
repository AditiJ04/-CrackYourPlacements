class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int mini=INT_MAX;
        int pro=0;
        int n=prices.size();

        for(int i=0;i<n;i++)
        {
             if(prices[i]<mini)
             {
                mini=prices[i];
             }
             else if(prices[i]>mini)
             {
                pro=max(pro,prices[i]-mini);
             }
        }
        return pro;
    }
};
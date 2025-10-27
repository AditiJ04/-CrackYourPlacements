class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int mnele=prices[0];

        int n=prices.size();

        for(int i=1;i<n;i++)
        {
            if(prices[i]>mnele)
            {
                mx=max(mx,prices[i]-mnele);
            }
            mnele=min(mnele,prices[i]);
        }
        return mx;
    }
};
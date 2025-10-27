class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int max_profit=0;
        int mn=prices[0];

        for(int i=1;i<n;i++)
        {
            int diff=prices[i]-mn;
            max_profit=max(max_profit,diff);
            mn=min(mn,prices[i]);
        }

        return max_profit;
    }
};
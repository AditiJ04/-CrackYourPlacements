class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();

        vector<bool>ans(n,false);

        for(int i=0;i<n;i++)
        {
            int nval=candies[i]+extraCandies;
            int mx=*max_element(candies.begin(),candies.end());

            if(nval>=mx) ans[i]=true;
        }

        return ans;
    }
};
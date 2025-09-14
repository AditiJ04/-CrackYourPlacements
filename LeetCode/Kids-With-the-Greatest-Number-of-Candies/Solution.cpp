class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>arr;
        int mx=0;
        for(int i=0;i<candies.size();i++)
        {
            mx=max(mx,candies[i]);
        }
        for(int i=0;i<candies.size();i++)
        {
            if((candies[i]+extraCandies)>=mx)
            {
                arr.push_back(true);
            }
            else if((candies[i]+extraCandies)<=mx)
            {
                arr.push_back(false);
            }
        }

        return arr;
    }
};
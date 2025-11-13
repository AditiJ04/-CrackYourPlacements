class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int n=houses.size();
        int m=heaters.size();

        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int mx=INT_MIN;
    
        for(int i=0;i<n;i++)
        {
            int prev=0;
            int mn=INT_MAX;

            for(int j=0;j<m;j++)
            {
                int diff=abs(houses[i]-heaters[j]);
               // if(diff==0) continue;
                mn=min(diff,mn);
            }
            mx=max(mx,mn);
        }

        return mx;
    }
};
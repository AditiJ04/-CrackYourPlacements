class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;

    vector<vector<ll>>PT;

    int solve(vector<int>&nums)
    {
        int m=nums.size();

        if(m<3) return 1;

        vector<int>L,R;

        int root=nums[0];
        for(int i=1;i<m;i++)
        {
            if(nums[i]<root) L.push_back(nums[i]);
            else R.push_back(nums[i]);
        }

        ll leftways=solve(L)%mod;
        ll rightways=solve(R)%mod;

        return (((leftways*rightways)%mod)*PT[m-1][L.size()])%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();

        PT.resize(n);

        for(int i=0;i<n;i++)
        {
            PT[i]=vector<long long>(i+1,1);

            for(int j=1;j<i;j++)
            {
                PT[i][j]=(PT[i-1][j-1]+PT[i-1][j])%mod;
            }
        }

        return (solve(nums)-1)%mod;
    }
};
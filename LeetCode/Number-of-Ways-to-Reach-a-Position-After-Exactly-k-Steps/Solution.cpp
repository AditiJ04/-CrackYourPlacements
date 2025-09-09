class Solution 
{
    map<pair<int, int>, int> dp;
    const long long int MOD = 1e9+7;

    int solve(int curr, int end, int k)
    {
        if(k == 0)
            return (curr == end)? 1:0;
        
        
        if(dp.find({curr, k}) != dp.end())
            return dp[{curr, k}];
        
        int left = solve(curr - 1, end, k - 1);
        int right = solve(curr + 1, end, k - 1);

        return dp[{curr, k}] = (left + right) % MOD;
    }

public:
    int numberOfWays(int startPos, int endPos, int k) {
        return solve(startPos, endPos, k) % MOD;    
    }
};
class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        max_gcd = max(nums)
        n = len(nums)
        dp = [[[0 for _ in range(max_gcd+1)] for _ in range(max_gcd+1)] for _ in range(n+1)]
        dp[0][0][0] = 1
        mod = 10**9+7
        gcd = [[0 for _ in range(max_gcd+1)] for _ in range(max_gcd+1)]
        for i in range(1, max_gcd+1):
            for j in range(1, max_gcd+1):
                gcd[i][j], gcd[j][i] = math.gcd(i,j),  math.gcd(i,j)

        for i in range(n):
            for g1 in range(max_gcd+1):
                for g2 in range(max_gcd+1):
                    dp[i+1][g1][g2] = (dp[i+1][g1][g2] + dp[i][g1][g2]) % mod
                    n_g1 = nums[i] if g1==0 else gcd[g1][nums[i]]
                    n_g2 = nums[i] if g2==0 else gcd[g2][nums[i]]
                    dp[i+1][n_g1][g2] = (dp[i+1][n_g1][g2] + dp[i][g1][g2]) % mod
                    dp[i+1][g1][n_g2] = (dp[i+1][g1][n_g2] + dp[i][g1][g2]) % mod
        res = 0
        for g in range(1,max_gcd+1):
            res = (res+dp[n][g][g]) % mod
        return res
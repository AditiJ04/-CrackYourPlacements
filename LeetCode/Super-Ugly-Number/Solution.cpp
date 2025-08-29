class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        if(n==1) return 1;
        int m=primes.size();

        vector<int>primeIndices(m,1);
        vector<int>superUgly(n+1);
        superUgly[1]=1;

        for(int i=2;i<=n;i++)
        {
            long long minval=INT_MAX;

            for(int j=0;j<m;j++)
            {
                minval=min(minval,(long long)primes[j]*superUgly[primeIndices[j]]);
            }
            superUgly[i]=(int)minval;

            for(int j=0;j<m;j++)
            {
                if(minval==(long long)primes[j]*superUgly[primeIndices[j]])
                {
                    primeIndices[j]++;
                }
            }
        }

        return superUgly[n];
    }
};
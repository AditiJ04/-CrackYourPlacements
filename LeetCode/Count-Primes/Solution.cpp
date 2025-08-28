class Solution {
public:
    int Checkprime(int n)
    {
        vector<int>Prime(n+1,1);
        int cnt=0;

        Prime[0]=Prime[1]=0;

        for(int i=2;i<=sqrt(n);i++)
        {
            if(Prime[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    Prime[j]=0;
                }
            }
        }

        for(int i=2;i<n;i++)
        {
            if(Prime[i]==1) cnt++;
        }
        return cnt;
    }
    int countPrimes(int n) {

        if(n==0 || n==1 || n==2) return 0;
    
        return Checkprime(n);
    }
};
class Solution {
public:
    int countPrimes(int n) {

        if(n==0 || n==1 || n==2) return 0;
        vector<int>P(n+1,1);

        P[0]=P[1]=0;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(P[i]==1)
            {
              for(int j=i*i;j<=n;j+=i)
              {
                P[j]=0;
              }
            }
        }

        int cnt=0;

        for(int i=2;i<n;i++)
        {
            if(P[i]==1) cnt++;
        }

        return cnt;
    }
};
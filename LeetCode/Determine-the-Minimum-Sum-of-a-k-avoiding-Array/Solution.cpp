class Solution {
public:
    int minimumSum(int n, int k) {
        int curr=1;
        int cnt=0;
        int sum=0;

        while(cnt!=n)
        {
            if((k-curr)>=curr || curr>=k)
            {
                sum+=curr;
                cnt++;
            }
            curr++;
        }

        return sum;
    }
};

//1 2 4 5 6
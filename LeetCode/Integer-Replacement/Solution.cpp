class Solution {
public:

    long long minOperations(int n)
    {
        if(n==1)
        {
            return 0;
        }
        long long even_case=INT_MAX-1,odd_case1=INT_MAX-1,odd_case2=INT_MAX-1;

        if(n%2==0)
        {
            even_case=minOperations(n/2);
        }
        else
        {
            if(n!=INT_MAX)
            {
            odd_case1=minOperations(n+1);
            }
            odd_case2=minOperations(n-1);
        }

        return 1+min({even_case,odd_case1,odd_case2});
    }
    int integerReplacement(int n) {

        if(n==INT_MAX) return 32;
        return (int)minOperations(n);
    }
};